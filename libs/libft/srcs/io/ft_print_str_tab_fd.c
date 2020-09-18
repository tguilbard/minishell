/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_tab_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 09:58:13 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/18 09:58:39 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_str_tab_fd(char *p_name, char **p_tab, int fd)
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
	while (p_tab && p_tab[index])
	{
		ft_putnbr_fd(index, fd);
		ft_putstr_fd("--->[", fd);
		ft_putstr_fd(p_tab[index], fd);
		ft_putstr_fd("]\n", fd);
		index++;
	}
	ft_putstr_fd("-----===-----\n", fd);
}
