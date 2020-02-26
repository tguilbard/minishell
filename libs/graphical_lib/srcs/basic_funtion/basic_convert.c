/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:47:18 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 12:48:26 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

char	*itoa(int n)
{
	char			*answer;
	int				i;
	long int		nbr;
	int				minus;

	answer = NULL;
	i = 1;
	nbr = n;
	minus = 0;
	while ((n >= 10 || n <= -10) && i++)
		n /= 10;
	minus = (nbr < 0) ? 1 : 0;
	nbr *= nbr < 0 ? -1 : 1;
	if (!(answer = malloc(sizeof(char) * i + 1 + minus)))
		return (NULL);
	answer[i + minus] = '\0';
	i = (!minus) ? i - 1 : i;
	while (nbr >= 10)
	{
		answer[i--] = nbr % 10 + 48;
		nbr /= 10;
	}
	answer[i] = nbr + 48;
	answer[0] = minus == 1 ? '-' : answer[0];
	return (answer);
}

int		convert_2di_1di(t_vector2 pos, t_vector2 size)
{
	return ((int)(pos.x) + ((int)(pos.y) * (int)(size.x)));
}

float	convert_2d_1d(t_vector2 pos, t_vector2 size)
{
	return (pos.x + (pos.y * size.x));
}
