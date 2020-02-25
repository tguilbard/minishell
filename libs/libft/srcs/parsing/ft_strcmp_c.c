/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:14:11 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/01/13 14:50:07 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strcmp_c(char *p_src, char p_target)
{
	int	i;

	i = 0;
	if (p_src == NULL || p_target == '\0')
		return (0);
	while (p_src[i] != '\0')
	{
		if (p_src[i] == p_target)
			return (true);
		i++;
	}
	return (false);
}
