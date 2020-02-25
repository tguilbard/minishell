/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:41:19 by ldutriez          #+#    #+#             */
/*   Updated: 2019/12/12 14:37:22 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_panel 		create_panel(t_vector2 p_pos, t_vector2 p_size,
					t_color p_color, t_button p_button)
{
	t_panel result;

	result.pos = p_pos;
	result.size = p_size;
	result.color = p_color;
	result.lst_button = p_button;
	return (result);
}

t_panel			*malloc_panel(t_vector2 p_pos, t_vector2 p_size,
					t_color p_color, t_button p_button)
{
	t_panel *result;

	result = (t_panel*)malloc(sizeof(t_panel));
	if (result == NULL)
		error_exit(12);

	*result = create_panel(p_pos, p_size, p_color, p_button);

	return (result);
}

void	draw_panel(t_application *app, t_panel p_panel)
{
	int i;

	i = 0;
	draw_rectangle(app, p_panel.pos, p_panel.size, p_panel.color);
	//printf("\nPanel has been drawn\n");

	draw_button(app, p_panel.lst_button);
	//print_vector2("draw_panel's button pos", p_panel.lst_button.pos);
	while (p_panel.lst_button.next != NULL)
	{
		draw_button(app, p_panel.lst_button);
		//print_vector2("draw_panel's button pos", p_panel.lst_button.pos);
		p_panel.lst_button = *p_panel.lst_button.next;
		i++;
	}
}

void 			destroy_panel(t_panel panel)
{
	(void)panel;
	//free(panel.lst_button);
	//panel.lst_button = NULL;
}

void 			free_panel(t_panel *panel)
{
	destroy_panel(*panel);
	free(panel);
}
