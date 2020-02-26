/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_primitive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:41:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/28 14:51:15 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void				draw_rectangle(t_vector2 pos, t_vector2 size, t_color color)
{
	float i;
	float j;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			put_pixel(create_vector2(pos.x + i, pos.y + j), color);
			j++;
		}
		i++;
	}
}

t_vector2_list		calc_circle(t_vector2 center, float radius)
{
	t_vector2_list	result;
	float			i;
	float			j;

	result = create_t_vector2_list(1);
	i = center.x - radius;
	while (i < center.x + radius)
	{
		j = center.y - radius;
		while (j < center.y + radius)
		{
			if (vector2_distance(center,
									create_vector2(i + 0.5, j + 0.5)) <= radius)
				t_vector2_list_push_back(&result, create_vector2(i, j));
			j++;
		}
		i++;
	}
	return (result);
}

void				draw_circle(t_vector2 center, int radius, t_color color)
{
	t_vector2_list	circle;
	size_t			i;

	circle = calc_circle(center, radius);
	i = 0;
	while (i < circle.size)
	{
		put_pixel(t_vector2_list_at(&circle, i), color);
		i++;
	}
	destroy_t_vector2_list(circle);
}
