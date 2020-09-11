/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_erase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:43:38 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/11 16:37:35 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	***ft_tab_erase(void ***tab, size_t index)
{
	void 	**tmp;
	size_t	cpy_i;

	tmp = *tab;
	cpy_i = 0;
	*tab = ft_tab_new(ft_tab_len(tmp) - 1);
	while (cpy_i < index)
	{
		(*tab)[cpy_i] = tmp[cpy_i];
		cpy_i++;
	}
	cpy_i++;
	while (tmp[cpy_i])
	{
		(*tab)[cpy_i - 1] = tmp[cpy_i];
		cpy_i++;
	}
	(*tab)[cpy_i - 1] = NULL;
	free(tmp);
	return (tab);
}