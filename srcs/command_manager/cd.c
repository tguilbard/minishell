/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 03:59:26 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/27 04:02:26 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_cd(char *path)
{
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
		ft_char_list_replace(&g_env, "PWD", "OLDPWD=");
		ft_char_list_replace(&g_env, , "PWD=");
	}
}
/*
** Modifier le PWD et OLDPWD de l'env
*/
