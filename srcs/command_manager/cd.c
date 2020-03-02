/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 03:59:26 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/02 18:28:02 by tguilbar         ###   ########.fr       */
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

void		mini_cd(char *path)
{
	size_t	i;

	if (path == NULL)
	{
		chdir("~");
		return ;
	}
	if (chdir(path) == -1)
	{
		printf("No such file or directory\n");
	}
	else
	{
		i = 0;
		while (g_env.data[i] && i < g_env.size)
		{
			if (ft_strnstr(g_env.data[i], "PWD", ft_strlen("PWD")))
			{
				find_oldpwd(i);
				change_pwd(i);
			}
			i++;
		}
	}
}
