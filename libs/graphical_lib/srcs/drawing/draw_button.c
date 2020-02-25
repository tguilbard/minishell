/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:41:37 by ldutriez          #+#    #+#             */
/*   Updated: 2019/12/12 14:37:10 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_button 		create_button(void)
{
	t_button result;

	result.pos = create_vector2(0, 0);
	result.size = create_vector2(0, 0);
	result.color = create_color(0, 0, 0, 255);
	result.text = NULL;
	result.next = NULL;
	return (result);
}

t_button			*malloc_button()
{
	t_button *result;

	result = (t_button*)malloc(sizeof(t_button));
	if (result == NULL)
		error_exit(13);

	*result = create_button();

	return (result);
}

void	draw_button(t_application *app, t_button p_button)
{
	draw_rectangle(app, p_button.pos, p_button.size, p_button.color);
	// printf("rectangle button has been drawn\n");
	mlx_string_put(app->mlx_ptr, app->win_ptr,
		(p_button.pos.x + p_button.size.x / 4),
		(p_button.pos.y + p_button.size.y / 1.5), 0xFFFFFF,
		p_button.text);
	// printf("text button has been drawn\n");
}

void 			destroy_button(t_button button)
{
	free(button.text);
	button.text = NULL;
}

void 			free_button(t_button *button)
{
	destroy_button(*button);
	free(button);
}
