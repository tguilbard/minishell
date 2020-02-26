/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_graphic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:31:19 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/13 14:30:57 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LGL_GRAPHIC_H
# define LGL_GRAPHIC_H

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

t_color				create_color(unsigned char p_r, unsigned char p_g,
										unsigned char p_b, unsigned char p_a);
t_color				*malloc_color(unsigned char p_r, unsigned char p_g,
										unsigned char p_b, unsigned char p_a);

void				destroy_color(t_color color);
void				free_color(t_color *color);

int					color_int(t_color color);
t_color				fuze_color(t_color old, t_color new);

void				print_color(char *name, t_color color);
char				*color_str(t_color color);

#endif
