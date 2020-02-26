/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:48:55 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 12:49:37 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void	lgl_putchar(char c)
{
	write(1, &c, 1);
}

void	lgl_putstr(char *s)
{
	if (s != NULL)
		write(1, s, lgl_strlen(s));
}

void	lgl_putnbr(int n)
{
	unsigned int nbr;
	unsigned int nb;

	nbr = 0;
	nb = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		nbr = (unsigned int)n * -1;
	}
	else if (n >= 0)
		nbr = (unsigned int)n;
	if (nbr >= 10)
		lgl_putnbr(nbr / 10);
	nb = nbr % 10 + '0';
	write(1, &nb, 1);
}
