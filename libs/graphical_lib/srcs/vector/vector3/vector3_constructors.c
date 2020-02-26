/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_constructors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:37:15 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:43:17 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_vector3	create_vector3(float p_x, float p_y, float p_z)
{
	t_vector3 result;

	result.x = p_x;
	result.y = p_y;
	result.z = p_z;
	return (result);
}

t_vector3	*malloc_vector3(float p_x, float p_y, float p_z)
{
	t_vector3 *result;

	result = (t_vector3 *)malloc(sizeof(t_vector3));
	if (result == NULL)
		error_exit(2);
	*result = create_vector3(p_x, p_y, p_z);
	return (result);
}
