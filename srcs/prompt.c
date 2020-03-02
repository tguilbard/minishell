/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:52:27 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/02 20:04:00 by ldutriez         ###   ########.fr       */
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

static void		*find_command(char *p_str)
{
	if (ft_strnstr(p_str, "echo", ft_strlen("echo")))
		return (&mini_echo); //param
	else if (ft_strnstr(p_str, "pwd", ft_strlen("pwd")))
		return (&mini_pwd);
	else if (ft_strnstr(p_str, "env", ft_strlen("env")))
		return (&mini_env);
	else if (ft_strnstr(p_str, "export", ft_strlen("export")))
		return (&mini_export);//param
	else if (ft_strnstr(p_str, "unset", ft_strlen("unset")))
		return (&mini_unset);//param
	else if (ft_strnstr(p_str, "cd", ft_strlen("cd")))
		return (&mini_cd);//param
	else if (ft_strnstr(p_str, "exit", ft_strlen("exit")))
		return (&mini_exit);//param
	else
	{
		ft_putstr(p_str);
		ft_putstr(": command not found\n");
		return (NULL);
	}
}

static char **check_param(char *param)
{
	void 	**result;
	size_t	index;
	size_t	start;

	result = ft_tab_new(0);
	index = 0;
	start = 0;
	while (param[index])
	{
		if (param[index] == ' ')
		{
			ft_add_to_tab((void*)ft_strsub(param, start, index - start), &result);
			start = index + 1;
		}
		else if (param[index] == '"')
		{
			index++;
			while (param[index] != '"')
				index++;
			ft_add_to_tab((void*)ft_strsub(param, start, index + 1 - start), &result);
			start = index + 1;
		}
		else if (param[index + 1] == '\0')
			ft_add_to_tab((void*)ft_strsub(param, start, index + 1 - start), &result);
		index++;
	}
	return ((char**)result);
}

int			main(int ac __attribute__((unused)),
								char **av __attribute__((unused)), char **env)
{
	char *str;
	char *user;

	set_environ(env);
	user = get_usr(env);
	ft_str_add_suffix(&user, ":");
	print_prompt(user);
	while (get_next_line(0, &str))
	{
		//find_command(str);
		ft_print_str_tab("args : ", check_param(str));
		free(str);
		print_prompt(user);
	}
	mini_exit();
	return (0);
}
