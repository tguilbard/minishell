/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_images_destructors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 02:51:04 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/31 03:22:50 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void			destroy_image_from_file(t_image image)
{
	(void)image;
}

void			free_image_from_file(t_image *image)
{
	destroy_image_from_file(*image);
	free(image);
}
