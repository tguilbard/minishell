/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4_constructors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:45:54 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:46:41 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_vector4	create_vector4(float p_x, float p_y, float p_z, float p_w)
{
	t_vector4 result;

	result.x = p_x;
	result.y = p_y;
	result.z = p_z;
	result.w = p_w;
	return (result);
}

t_vector4	*malloc_vector4(float p_x, float p_y, float p_z, float p_w)
{
	t_vector4 *result;

	result = (t_vector4 *)malloc(sizeof(t_vector4));
	if (result == NULL)
		error_exit(3);
	*result = create_vector4(p_x, p_y, p_z, p_w);
	return (result);
}
