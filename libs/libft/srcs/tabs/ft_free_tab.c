/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:13:46 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/03/05 13:12:05 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(void **tab)
{
	int	index;

	index = 0;
	if (tab == NULL)
		return ;
	while (tab[index] != NULL)
	{
		free(tab[index]);
		index++;
	}
	free(tab);
}
