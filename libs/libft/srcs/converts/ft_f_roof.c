/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_roof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:11:18 by ldutriez          #+#    #+#             */
/*   Updated: 2019/12/02 16:50:22 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_f_roof(float p_value)
{
	float	rounded_value;
	int		i_value;

	if (p_value == 0)
		return (p_value);
	i_value = p_value;
	if (p_value < 0)
	{
		rounded_value = i_value;
		return (rounded_value);
	}
	rounded_value = p_value - i_value;
	if (rounded_value == 0)
	{
		rounded_value = p_value;
		return (rounded_value);
	}
	else
		rounded_value = i_value + 1;
	return (rounded_value);
}
