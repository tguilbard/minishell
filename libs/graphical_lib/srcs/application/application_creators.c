/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_creators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:58:48 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 17:32:43 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_application *g_application = NULL;

static void		create_window(t_vector2 p_size)
{
	g_application->size = p_size;
	g_application->win_ptr = mlx_new_window(g_application->mlx_ptr,
			(int)(g_application->size.x), (int)(g_application->size.y),
			g_application->prog_name);
	if (g_application->win_ptr == NULL)
		error_exit(6);
	g_application->img_ptr = mlx_new_image(g_application->mlx_ptr,
			(int)(g_application->size.x), (int)(g_application->size.y));
	if (g_application->img_ptr == NULL)
		error_exit(7);
	g_application->pixels = mlx_get_data_addr(g_application->img_ptr,
			&(g_application->bits_per_pixel), &(g_application->size_line),
			&(g_application->endian));
}

void			open_application(t_vector2 p_size, char *p_prog_name)
{
	g_application = (t_application *)malloc(sizeof(t_application));
	if (g_application == NULL)
		error_exit(4);
	g_application->mlx_ptr = mlx_init();
	if (g_application->mlx_ptr == NULL)
		error_exit(5);
	g_application->prog_name = p_prog_name;
	create_window(p_size);
}

void			resize_application(t_vector2 new_size)
{
	destroy_application(*g_application);
	destroy_image(g_application);
	create_window(new_size);
}
