/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:41:30 by ldutriez          #+#    #+#             */
/*   Updated: 2019/12/09 13:41:32 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void draw_line(t_application *application, t_vector2 p_a, t_vector2 p_b, t_color color, float width)
{
	t_vector2_list line;
	t_vector2_list circle;
	t_vector2 tmp2;
	t_vector2 tmp;
	t_vector2 tmp3;
	size_t i;
	size_t j;

	circle = calc_circle(create_vector2(0, 0), width / 2.0f);
	line = calc_line(p_a, p_b);

	i = 0;
	while (i < circle.size)
	{
		tmp2 = t_vector2_list_at(&circle, i);
		j = 0;
		while (j < line.size)
		{
			tmp = t_vector2_list_at(&line, j);
			tmp3 = create_vector2(tmp.x + tmp2.x, tmp.y + tmp2.y);
			put_pixel(application, tmp3, color);
			j++;
		}
		i++;
	}
	destroy_t_vector2_list(circle);
	destroy_t_vector2_list(line);
}
