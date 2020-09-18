/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:17:01 by user42            #+#    #+#             */
/*   Updated: 2020/09/18 10:06:58 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	t_char_list	g_env;

static char	**take_path(void)
{
	char	*raw_path;
	char	**path;
	int		env_index;

	env_index = find_env_var("PATH");
	raw_path = NULL;
	path = NULL;
	if (env_index != -1)
	{
		raw_path = g_env.data[env_index] + 5;
		path = ft_split(raw_path, ':');
	}
	return (path);
}

static int	check_path(char **path, char **p_param, int i, char *tmp)
{
	int		pid;
	int		status;

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
		{
			free(path[i]);
			path[i] = NULL;
		}
		free(path);
		path = NULL;
		return (0);
	}
	return (1);
}

int			find_cmd(char **p_param)
{
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	path = take_path();
	tmp = p_param[0];
	while (path && path[i])
	{
		ft_str_add_suffix(&(path[i]), "/");
		ft_str_add_suffix(&(path[i]), tmp);
		p_param[0] = path[i];
		if (check_path(path, p_param, i, tmp) == 0)
			return (0);
		i++;
	}
	ft_putstr_fd(tmp, 2);
	ft_putstr_fd(": command not found\n", 2);
	free(path);
	path = NULL;
	p_param[0] = tmp;
	return (1);
}
