/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_behavior.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:01:28 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 17:31:01 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void			put_pixel(t_vector2 pos, t_color color)
{
	int		pixel_index;
	t_color	base;

	if (pos.x < 0 || pos.x >= g_application->size.x || pos.y < 0 ||
												pos.y >= g_application->size.y)
		return ;
	pixel_index = convert_2di_1di(pos, g_application->size) * 4;
	base = create_color(g_application->pixels[pixel_index + RED_COMP],
		g_application->pixels[pixel_index + GREEN_COMP],
		g_application->pixels[pixel_index + BLUE_COMP], 255);
	color = fuze_color(base, color);
	g_application->pixels[pixel_index + RED_COMP] = color.r;
	g_application->pixels[pixel_index + GREEN_COMP] = color.g;
	g_application->pixels[pixel_index + BLUE_COMP] = color.b;
}

void			set_pixel(t_vector2 pos, t_color color)
{
	int pixel_index;

	if (pos.x < 0 || pos.x >= g_application->size.x || pos.y < 0 ||
												pos.y >= g_application->size.y)
		return ;
	pixel_index = convert_2di_1di(pos, g_application->size) * 4;
	g_application->pixels[pixel_index + RED_COMP] = color.r;
	g_application->pixels[pixel_index + GREEN_COMP] = color.g;
	g_application->pixels[pixel_index + BLUE_COMP] = color.b;
}

void			clear_screen(void)
{
	size_t i;
	size_t j;

	mlx_clear_window(g_application->mlx_ptr, g_application->win_ptr);
	i = 0;
	while (i < g_application->size.x)
	{
		j = 0;
		while (j < g_application->size.y)
		{
			set_pixel(create_vector2(i, j), create_color(0, 0, 0, 255));
			j++;
		}
		i++;
	}
}

void			render_screen(void)
{
	mlx_put_image_to_window(g_application->mlx_ptr, g_application->win_ptr,
						g_application->img_ptr, 0, 0);
}
