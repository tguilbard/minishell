/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 03:59:26 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/12 12:51:00 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list g_env;

static void	find_oldpwd(size_t i)
{
	int j;

	j = find_env_var("OLDPWD");
	if (j != -1)
		ft_char_list_replace(&g_env, g_env.data[j], ft_strjoin("OLD",
																g_env.data[i]));
}

static void	change_pwd(size_t i)
{
	char *pwd;

	pwd = get_pwd();
	ft_str_add_prefixe("PWD=", &pwd);
	ft_char_list_replace(&g_env, g_env.data[i], pwd);
}

int		mini_cd(char **path)
{
	size_t	i;
	int		j;

	if (path[1] == NULL)
	{
		j = find_env_var("HOME");
		if (j > -1)
		{
			chdir(g_env.data[j] + 5);
			i = find_env_var("PWD");
			find_oldpwd(i);
			change_pwd(i);
			return (0);
		}
		ft_putstr("minishell: cd: HOME not set");
		return (1);
	}
	if (chdir(path[1]) == -1)
	{
		ft_putstr(path[1]);
		ft_putstr(": no such file or directory\n");
		return (1);
	}
	i = find_env_var("PWD");
	find_oldpwd(i);
	change_pwd(i);
	return (0);
}
