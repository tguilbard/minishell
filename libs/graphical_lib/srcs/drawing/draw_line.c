/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:41:30 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 17:33:50 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void	draw_line(t_vector2 p_a_b[2], t_color color, float width)
{
	t_vector2_list	line;
	t_vector2_list	circle;
	t_vector2		tmps[3];
	size_t			i;
	size_t			j;

	circle = calc_circle(create_vector2(0, 0), width / 2.0f);
	line = calc_line(p_a_b[0], p_a_b[1]);
	i = 0;
	while (i < circle.size)
	{
		tmps[1] = t_vector2_list_at(&circle, i);
		j = 0;
		while (j < line.size)
		{
			tmps[0] = t_vector2_list_at(&line, j);
			tmps[2] = create_vector2(tmps[0].x + tmps[1].x,
														tmps[0].y + tmps[1].y);
			put_pixel(tmps[2], color);
			j++;
		}
		i++;
	}
	destroy_t_vector2_list(circle);
	destroy_t_vector2_list(line);
}
