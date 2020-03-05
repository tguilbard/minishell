/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 03:59:26 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/05 21:38:09 by ldutriez         ###   ########.fr       */
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

void		mini_cd(char **path)
{
	size_t	i;
	int		j;

	if (path[0] == NULL)
	{
		j = find_env_var("HOME");
		if (j > -1)
		{
			chdir(g_env.data[j] + 5);
			i = find_env_var("PWD");
			find_oldpwd(i);
			change_pwd(i);
		}
		return ;
	}
	if (chdir(path[0]) == -1)
	{
		ft_putstr(path[0]);
		ft_putstr(": no such file or directory\n");
		return ;
	}
	i = find_env_var("PWD");
	find_oldpwd(i);
	change_pwd(i);
}
