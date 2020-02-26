/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_panel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:52:40 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 13:38:55 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LGL_PANEL_H
# define LGL_PANEL_H

typedef struct		s_button
{
	t_vector2		pos;
	t_vector2		size;
	t_color			color;
	char			*text;
	struct s_button	*next;
}					t_button;

t_button			create_button(t_vector2 pos, t_vector2 size, t_color color,
																	char *text);
t_button			*malloc_button(t_vector2 pos, t_vector2 size, t_color color,
																	char *text);
void				draw_button(t_button p_button);
void				destroy_button(t_button button);
void				free_button(t_button *button);

typedef struct		s_panel
{
	t_vector2		pos;
	t_vector2		size;
	t_color			color;
	t_button		lst_button;
}					t_panel;

t_panel				create_panel(t_vector2 p_pos, t_vector2 p_size,
						t_color p_color, t_button p_button);
t_panel				*malloc_panel(t_vector2 p_pos, t_vector2 p_size,
						t_color p_color, t_button p_button);
void				draw_panel(t_panel p_panel);
void				destroy_panel(t_panel panel);
void				free_panel(t_panel *panel);

#endif
