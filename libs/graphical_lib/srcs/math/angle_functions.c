/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 07:35:35 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 13:21:50 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

float	degree_to_radian(float p_degree)
{
	return (p_degree * 3.141592653589 / 180);
}

float	radian_to_degree(float p_radian)
{
	return (p_radian * 180 / 3.141592653589);
}
