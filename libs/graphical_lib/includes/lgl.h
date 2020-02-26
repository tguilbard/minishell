/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:43:11 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 17:41:54 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LGL_H
# define LGL_H

# include "lgl_includes.h"

size_t			lgl_strlen(char *str);
char			*lgl_strnew(size_t size);
char			*itoa(int n);
char			*ftoa(float n, int precision);
void			lgl_putchar(char c);
void			lgl_putstr(char *str);
void			lgl_putnbr(int nbr);
void			lgl_stradd_front(char *s1, char **s2);
void			lgl_stradd_back(char **s1, char *s2);
char			*lgl_strdup(char *s1);
char			*lgl_strcat(char *s1, char *s2);
char			*lgl_strcpy(char *dst, char *src);
char			*lgl_strcut(char **src, char c);
char			*lgl_strsub(char *s, unsigned int start, size_t len);
void			lgl_strclr(char *s);

void			draw_rectangle(
								t_vector2 pos, t_vector2 size, t_color color);
void			draw_circle(
								t_vector2 center, int radius, t_color color);
void			draw_line(t_vector2 p_a_b[2],
													t_color color, float width);

t_vector2_list	calc_line(t_vector2 start, t_vector2 end);
t_vector2_list	calc_circle(t_vector2 center, float radius);

float			degree_to_radian(float p_degree);
float			radian_to_degree(float p_radian);
float			power(float nbr, int power);

#endif
