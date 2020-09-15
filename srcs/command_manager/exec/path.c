/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:17:01 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 10:21:45 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	t_char_list	g_env;

char	**take_path(void)
{
	char	*raw_path;
	char	**path;

	raw_path = g_env.data[find_env_var("PATH")] + 5;
	path = ft_split(raw_path, ':');
	return (path);
}

int		find_cmd(char **p_param)
{
	char	**path;
	char	*tmp;
	int		i;
	int		pid;
	int		status;

	i = 0;
	path = take_path();
	tmp = p_param[0];
	while (path[i])
	{
		ft_str_add_suffix(&(path[i]), "/");
		ft_str_add_suffix(&(path[i]), tmp);
		p_param[0] = path[i];
		pid = fork();
		if (pid == 0)
		{
			if (execve(p_param[0], p_param, g_env.data) == -1)
				exit(-1);
			exit(0);
		}
		waitpid(pid, &status, 0);
		free(p_param[0]);
		if (status == 0 || status == 256)
		{
			p_param[0] = tmp;
			while (path[++i])
				free(path[i]);
			free(path);
			return (0);
		}
		i++;
	}
	ft_putstr(tmp, 2);
	ft_putstr(": command not found\n", 2);
	free(path);
	p_param[0] = tmp;
	return (1);
}
