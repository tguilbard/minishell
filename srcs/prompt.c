/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:52:27 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/05 21:03:10 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

static void		print_prompt(char *user)
{
	write(1, user, ft_strlen(user));
}

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

static void		main_execution(char *user)
{
	char *str;
	char **param;

	param = NULL;
	print_prompt(user);
	while (get_next_line(0, &str))
	{
		//find_command(str);
		param = get_param(str);
		apply_function(find_command(param[0]), &(param[1]));
		free(str);
		print_prompt(user);
		// system("leaks miniShell");
	}
	ft_free_tab((void**)param);
	mini_exit();
}

void forker(char *user)
{
	int status;
	int	pid;

	pid = 1;
	status = 2;
	signal(SIGINT, SIG_IGN);
	while (pid != 0 && status != 0)
	{
		if ((pid = fork()) == -1)
			ft_putstr("fork failed");
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			main_execution(user);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (status != 0)
				ft_putchar('\n');
		}
	}
}

int				main(int ac __attribute__((unused)),
								char **av __attribute__((unused)), char **env)
{
	char *user;

	set_environ(env);
	user = get_usr();
	ft_str_add_suffix(&user, ":");
	forker(user);
	return (0);
}
