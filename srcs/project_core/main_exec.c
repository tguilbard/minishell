/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 23:18:23 by user42            #+#    #+#             */
/*   Updated: 2020/09/11 16:05:04 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;
extern int g_env_fd[2];
extern int g_ret;

static void	*find_command(char *p_str)
{
	if (p_str == NULL)
		return (NULL);
	else if (ft_strcmp(p_str, "echo"))
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
	else if (ft_strcmp_c(p_str, '/'))
		return (&mini_exec);
	else if (ft_strcmp(p_str, "exit"))
		return (&mini_exit);
	ft_putstr(p_str, 2);
	ft_putstr(": command not found\n", 2);
	return (NULL);
}

static int	apply_function(int (*f)(char **param), char **param)
{
	if (f == NULL)
		return (g_ret);
	return (f(param));
}

void		child_killer(int sig)
{
	char	*pwd;
	int		i;

	i = 0;
	(void)sig;
	close(g_env_fd[0]);
	while (g_env.data[i])
	{
		write(g_env_fd[1], g_env.data[i], ft_strlen(g_env.data[i]));
		write(g_env_fd[1], "\n", 1);
		i++;
	}
	pwd = get_pwd();
	ft_putstr(pwd, g_env_fd[1]);
	free(pwd);
	ft_putchar(' ', g_env_fd[1]);
	ft_putnbr(g_ret, g_env_fd[1]);
	close(g_env_fd[1]);
	if (sig != 1 && sig != 3)
		ft_putchar('\n', 1);
	exit(sig);
}

void		main_execution(void)
{
	char	*str;
	t_param *param;
	size_t	n;
	// int		stdout;

	print_prompt();
	if (get_next_line(0, &str))
	{
		signal(SIGQUIT, child_killer);
		n = 0;
		param = get_param(str);
		free(str);
		while (param->param[n])
		{
			redirection(param, n);
			g_ret = apply_function(find_command(param->param[n][0]),
															param->param[n]);
			n++;
		}
		close(0);
		close(1);
		free_param(param);
		child_killer(1);
	}
	mini_exit(0);
}
