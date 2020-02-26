/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_power.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:52:02 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:26:38 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

float	power(float nbr, int power)
{
	float result;

	result = 1;
	while (power > 0)
	{
		result *= nbr;
		power--;
	}
	return (result);
}
