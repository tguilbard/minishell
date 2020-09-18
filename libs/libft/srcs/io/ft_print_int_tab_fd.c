/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 09:56:43 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/18 09:57:36 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_tab_fd(char *p_name, int *p_tab, size_t len, int fd)
{
	size_t		index;

	index = 0;
	if (p_name != NULL)
	{
		ft_putchar_fd('{', fd);
		ft_putstr_fd(p_name, fd);
		ft_putstr_fd("}\n", fd);
	}
	ft_putstr_fd("-----===-----\n", fd);
	while (p_tab && index < len)
	{
		ft_putnbr_fd(index, fd);
		ft_putstr_fd("--->[", fd);
		ft_putnbr_fd(p_tab[index], fd);
		ft_putstr_fd("]\n", fd);
		index++;
	}
	ft_putstr_fd("-----===-----\n", fd);
}
