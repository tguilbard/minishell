/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:52:27 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/06 10:21:04 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;
int					g_env_fd[2];

static char		*get_usr(void)
{
	char	*result;
	int		index;

	index = find_env_var("USER");
	if (index != -1)
	{
		result = ft_strdup(g_env.data[index] + 5);
		return (result);
	}
	return (ft_strdup("unknow"));
}

static void		print_prompt(void)
{
	int		i;
	int		last;
	char	*str[2];

	str[0] = get_pwd();
	i = 0;
	last = 0;
	while (str[0][i])
	{
		if (str[0][i] == '/')
			last = i;
		i++;
	}
	str[1] = ft_strsub(str[0], last, i - last);
	free(str[0]);
	ft_putstr(str[1]);
	free(str[1]);
	ft_putstr(" (");
	str[0] = get_usr();
	ft_putstr(str[0]);
	free(str[0]);
	ft_putstr("):");
}

static void		*find_command(char *p_str)
{
	if (ft_strcmp(p_str, "echo"))
		return (&mini_echo);
	else if (ft_strcmp(p_str, "pwd"))
		return (&mini_pwd);
	else if (ft_strcmp(p_str, "env"))
		return (&mini_env);
	else if (ft_strcmp(p_str, "export"))
		return (&mini_export);
	else if (ft_strcmp(p_str, "unset"))
		return (&mini_unset);
	else if (ft_strcmp(p_str, "cd"))
		return (&mini_cd);
	else if (ft_strcmp(p_str, "help"))
		return (&help);
	else if (ft_strcmp(p_str, "exit"))
		return (&mini_exit);
	else
	{
		ft_putstr(p_str);
		ft_putstr(": command not found\n");
		return (NULL);
	}
}

static void		apply_function(void (*f)(char **param), char **param)
{
	if (f == NULL)
		return ;
	f(param);
}

static void		main_execution(void)
{
	char	*str;
	char	***param;
	size_t	n;

	param = NULL;
	print_prompt();
	while (get_next_line(0, &str))
	{
		n = 0;
		param = get_param(str);
		while (param[n])
		{
			apply_function(find_command(param[n][0]), &(param[n][1]));
			n++;
		}
		free(str);
		print_prompt();
		while (param[n])
		{
			ft_free_tab((void**)param[n]);
			n++;
		}
	}
	mini_exit();
}

void	child_killer(int sig)
{
	int	i;

	i = 0;
	(void)sig;
	close(g_env_fd[0]);
	while (g_env.data[i])
	{
		write(g_env_fd[1], g_env.data[i], ft_strlen(g_env.data[i]));
		write(g_env_fd[1], "\n", 1);
		i++;
	}
	close(g_env_fd[1]);
	exit(1);
}

void take_environ(void)
{
	char	*str;
	int		ret;
	char	**tab;

	tab = (char	**)ft_tab_new(0);
	close(g_env_fd[1]);
	ret = 1;
	while ((ret = get_next_line(g_env_fd[0], &str)) != -1)
	{
		if (ret == 0)
		{
			destroy_t_char_list(g_env);
			g_env = create_char_list(ft_tab_len((void **)tab));
			g_env.data = (char **)ft_tab_cpy((void **)g_env.data, (void **)tab);
			free(tab);
			close(g_env_fd[0]);
			return ;
		}
		ft_add_to_tab((void *)str, (void ***)&tab);
	}
	ft_putstr("relink failed");
	exit (0);
}

void			forker(void)
{
	int status;
	int	pid;

	pid = 1;
	status = 2;
	signal(SIGINT, SIG_IGN);
	while (pid != 0 && status != 0)
	{
		if (pipe(g_env_fd) == -1)
		{
			ft_putstr("relink failed");
			exit (0);
		}
		if ((pid = fork()) == -1)
			ft_putstr("fork failed");
		if (pid == 0)
		{
			signal(SIGINT, child_killer);
			main_execution();
		}
		else
		{
			waitpid(pid, &status, 0);
			if (status != 0)
			{
				take_environ();
				ft_putchar('\n');
			}
		}
	}
}

int				main(int ac __attribute__((unused)),
								char **av __attribute__((unused)), char **env)
{
	set_environ(env);
	forker();
	return (0);
}
