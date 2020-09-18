/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 23:24:58 by user42            #+#    #+#             */
/*   Updated: 2020/09/18 10:04:24 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;
extern int g_env_fd[2];
extern int g_ret;

static void	take_environ_core(char **tab, char *str)
{
	char	*pwd;
	int		i;

	destroy_t_char_list(g_env);
	g_env = create_char_list(ft_tab_len((void **)tab));
	g_env.data = (char **)ft_tab_cpy((void **)g_env.data, (void **)tab);
	free(tab);
	i = 0;
	while (str && !ft_is_whitespaces(str[i]))
		i++;
	pwd = ft_strsub(str, 0, i);
	chdir(pwd);
	free(pwd);
	g_ret = atoi(str + i);
	close(g_env_fd[0]);
}

void		take_environ(void)
{
	char	**tab;
	char	*str;
	int		ret;

	tab = (char **)ft_tab_new(0);
	close(g_env_fd[1]);
	ret = 1;
	while ((ret = get_next_line(g_env_fd[0], &str)) != -1)
	{
		if (ret == 0)
		{
			take_environ_core(tab, str);
			free(str);
			return ;
		}
		ft_add_to_tab((void *)str, (void ***)&tab);
	}
	ft_putstr_fd("relink failed\n", 2);
	exit(0);
}

int			take_return(void)
{
	char	*str;
	int		ret;
	int		tmp;

	close(g_env_fd[1]);
	while ((ret = get_next_line(g_env_fd[0], &str)) != -1)
	{
		if (ret == 0)
		{
			tmp = ft_atoi(str);
			close(g_env_fd[0]);
			free(str);
			return (tmp);
		}
		free(str);
	}
	ft_putstr_fd("relink failed\n", 2);
	exit(0);
}

static void	forker_parent(int status)
{
	if (status != 0)
		take_environ();
	else
		exit(take_return());
	if (status == 768)
		ft_putstr_fd("minishell quit process\n", 2);
}

void		forker(void)
{
	int status;
	int	pid;

	pid = 1;
	status = 2;
	while (pid != 0 && status != 0)
	{
		if (pipe(g_env_fd) == -1)
		{
			ft_putstr_fd("relink failed", 2);
			exit(0);
		}
		if ((pid = fork()) == -1)
			ft_putstr_fd("fork failed", 2);
		if (pid == 0)
		{
			signal(SIGINT, child_killer);
			main_execution();
		}
		else
		{
			waitpid(pid, &status, 0);
			forker_parent(status);
		}
	}
}
