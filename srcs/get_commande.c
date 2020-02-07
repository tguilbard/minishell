/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commande.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:46:38 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/07 11:52:29 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	test_command(char *p_src, char *p_target)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (p_src == NULL || p_target == NULL)
		return (0);
	while (p_target[j] == ' ' && p_target[j])
		j++;
	while (p_target[j] != ' ' && p_target[j])
		j++;
	p_target[j] = '\0';
	while (p_src[i] != '\0' || p_target[i] != '\0')
	{
		if (p_src[i] != p_target[i])
			return (false);
		i++;
	}
	p_target[j] = ' ';
	return (true);
}


