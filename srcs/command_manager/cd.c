/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 03:59:26 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/27 12:05:49 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list g_env;

static void	find_oldpwd(size_t i)
{
	size_t j;

	j = 0;
	while (g_env.data[j] && j < g_env.size)
	{
		if (ft_strnstr(g_env.data[j], "OLDPWD", ft_strlen("OLDPWD")))
				ft_char_list_replace(&g_env, g_env.data[j], ft_strjoin("OLD", g_env.data[i]));
		j++;
	}
}

void		mini_cd(char *path)
{
	size_t i;

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
				ft_char_list_replace(&g_env, g_env.data[i], ft_strjoin("PWD=", get_pwd()));
			}
			i++;
		}
	}
}
