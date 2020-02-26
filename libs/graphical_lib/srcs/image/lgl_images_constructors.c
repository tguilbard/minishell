/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_images_constructors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:18:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 17:42:51 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_image	create_image(int width, int height)
{
	t_image result;

	result.img_ptr = mlx_new_image(g_application->mlx_ptr,
						(int)(width), (int)(height));
	result.pixels = mlx_get_data_addr(result.img_ptr, &(result.bits_per_pixel),
						&(result.size_line), &(result.endian));
	return (result);
}

t_image	create_image_from_file(char *path)
{
	t_image result;

	result.width = 0;
	result.height = 0;
	result.bits_per_pixel = 0;
	result.size_line = 0;
	result.endian = 0;
	result.img_ptr = mlx_xpm_file_to_image(g_application->mlx_ptr, path,
										&(result.width), &(result.height));
	result.pixels = mlx_get_data_addr(result.img_ptr, &(result.bits_per_pixel),
										&(result.size_line), &(result.endian));
	return (result);
}

t_image	*malloc_image_from_file(char *path)
{
	t_image *result;

	result = (t_image *)malloc(sizeof(t_image));
	if (result == NULL)
		error_exit(15);
	*result = create_image_from_file(path);
	return (result);
}
