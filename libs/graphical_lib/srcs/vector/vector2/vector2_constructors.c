/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_constructors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:32:32 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:35:27 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_vector2	create_vector2(float p_x, float p_y)
{
	t_vector2 result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}

t_vector2	*malloc_vector2(float p_x, float p_y)
{
	t_vector2 *result;

	result = (t_vector2 *)malloc(sizeof(t_vector2));
	if (result == NULL)
		error_exit(1);
	*result = create_vector2(p_x, p_y);
	return (result);
}
