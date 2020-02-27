/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:52:27 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/26 23:45:12 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_prompt(char *user)
{
	write(1, user, ft_strlen(user));
}

static char	*get_usr(char **p_env)
{
	char	*result;
	int		index;

	index = 0;
	while (p_env[index])
	{
		result = strnstr(p_env[index], "USER=", 5);
		if (result != NULL)
		{
			result = ft_strdup(result + 5);
			return (result);
		}
		index++;
	}
	return (ft_strdup("unknow"));
}

__attribute__((destructor)) void no_crtl(void)
{
		fork();
}

void		treatment(char *p_str) //J'ai l'impression qu'un foncteur fera l'affaire
{
	if (ft_strnstr(p_str, "echo", ft_strlen("echo")))
		mini_echo(p_str + 5);
	else if (ft_strnstr(p_str, "pwd", ft_strlen("pwd")))
		mini_pwd();
	else if (ft_strnstr(p_str, "env", ft_strlen("env")))
		mini_env();
	else if (ft_strnstr(p_str, "export", ft_strlen("export")))
		mini_export(p_str + 7);
	else if (ft_strnstr(p_str, "unset", ft_strlen("unset")))
		mini_unset(p_str + 6);
	else if (ft_strnstr(p_str, "cd", ft_strlen("cd")))
		mini_cd(p_str + 3);
	else if (ft_strnstr(p_str, "exit", ft_strlen("exit")))
			mini_exit();
	else
	{
		ft_putstr(p_str);
		ft_putstr(": command not found\n");
	}
}

int			main(int ac __attribute__ ((unused)), char **av __attribute__ ((unused)), char **env)
{
	char *str;
	char *user;

	set_environ(env);
	user = get_usr(env);
	ft_str_add_suffix(&user, ":");
	print_prompt(user);
	while (get_next_line(0, &str))
	{
		//parsing
		treatment(str);
		free(str);
		print_prompt(user);
	}
	mini_exit();
	return (0);
}
