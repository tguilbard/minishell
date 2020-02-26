/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:41:37 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 00:51:41 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_button	create_button(t_vector2 pos, t_vector2 size, t_color color,
																	char *text)
{
	t_button result;

	result.pos = pos;
	result.size = size;
	result.color = color;
	result.text = lgl_strdup(text);
	result.next = NULL;
	return (result);
}

t_button	*malloc_button(t_vector2 pos, t_vector2 size, t_color color,
																	char *text)
{
	t_button *result;

	result = (t_button*)malloc(sizeof(t_button));
	if (result == NULL)
		error_exit(13);
	*result = create_button(pos, size, color, text);
	return (result);
}

void		draw_button(t_button p_button)
{
	draw_rectangle(p_button.pos, p_button.size, p_button.color);
	mlx_string_put(g_application->mlx_ptr, g_application->win_ptr,
		(p_button.pos.x + p_button.size.x / 4),
		(p_button.pos.y + p_button.size.y / 1.5), 0xFFFFFF,
		p_button.text);
}

void		destroy_button(t_button button)
{
	free(button.text);
	button.text = NULL;
}

void		free_button(t_button *button)
{
	destroy_button(*button);
	free(button);
}
