/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:00:33 by ldutriez          #+#    #+#             */
/*   Updated: 2020/04/01 11:01:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_tab(char *p_name, int *p_tab, size_t len, int fd)
{
	size_t		index;

	index = 0;
	if (p_name != NULL)
	{
		ft_putchar('{', fd);
		ft_putstr(p_name, fd);
		ft_putstr("}\n", fd);
	}
	ft_putstr("-----===-----\n", fd);
	while (p_tab && index < len)
	{
		ft_putnbr(index, fd);
		ft_putstr("--->[", fd);
		ft_putnbr(p_tab[index], fd);
		ft_putstr("]\n", fd);
		index++;
	}
	ft_putstr("-----===-----\n", fd);
}
