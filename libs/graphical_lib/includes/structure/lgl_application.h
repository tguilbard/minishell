/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_application.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:28:14 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 01:05:53 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LGL_APPLICATION_H
# define LGL_APPLICATION_H

typedef struct	s_application
{
	void		*mlx_ptr;
	void		*win_ptr;

	void		*img_ptr;
	char		*pixels;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	char		*prog_name;
	t_vector2	size;
}				t_application;

extern t_application *g_application;

void			open_application(t_vector2 p_size, char *p_prog_name);
void			resize_application(t_vector2 new_size);

void			destroy_application();
void			destroy_image();
void			free_application();

void			clear_screen();
void			put_pixel(t_vector2 pos, t_color color);
void			set_pixel(t_vector2 pos, t_color color);

void			render_screen();
void			application_add_key_control(
					int event, int (*funct)(int, void *), void *param);
void			application_add_mouse_control(
					int event, int (*funct)(int, void *), void *param);
void			application_add_exit_control(
					int event, int (*funct)(void));
void			application_update(
					int (*funct)(void *), void *param);
void			run_application();

#endif
