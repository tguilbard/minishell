/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:10:16 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/31 02:51:57 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LGL_IMAGE_H
# define LGL_IMAGE_H

typedef struct	s_image
{
	void		*img_ptr;

	int			width;
	int			height;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*pixels;
}				t_image;

t_image			create_image(int width, int height);
t_image			create_image_from_file(char *path);
t_image			*malloc_image_from_file(char *path);
void			destroy_image_from_file(t_image image);
void			free_image_from_file(t_image *image);

#endif
