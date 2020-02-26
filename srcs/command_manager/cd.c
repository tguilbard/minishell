/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:29:09 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/26 22:04:12 by tguilbar         ###   ########.fr       */
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
		printf("No such file or directory\n");
}
/*
** Modifier le PWD et OLDPWD de l'env
*/
