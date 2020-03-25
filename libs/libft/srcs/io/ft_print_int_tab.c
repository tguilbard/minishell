/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:00:33 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/25 00:55:37 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_tab(char *p_name, int *p_tab, size_t len)
{
	size_t		index;

	index = 0;
	if (p_name != NULL)
	{
		ft_putchar('{');
		ft_putstr(p_name, 1);
		ft_putstr("}\n", 1);
	}
	ft_putstr("-----===-----\n", 1);
	while (p_tab && index < len)
	{
		ft_putnbr(index);
		ft_putstr("--->[", 1);
		ft_putnbr(p_tab[index]);
		ft_putstr("]\n", 1);
		index++;
	}
	ft_putstr("-----===-----\n", 1);
}
