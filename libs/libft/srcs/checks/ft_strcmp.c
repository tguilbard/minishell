/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:55:32 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/02/25 21:18:14 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strcmp(char *p_src, char *p_target)
{
	size_t	i;

	i = 0;
	if (p_src == NULL || p_target == NULL)
		return (0);
	while (p_src[i] != '\0' || p_target[i] != '\0')
	{
		if (p_src[i] != p_target[i])
			return (false);
		i++;
	}
	return (true);
}
