/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_destructors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:59:47 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 17:29:59 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void			destroy_application(void)
{
	mlx_destroy_window(g_application->mlx_ptr, g_application->win_ptr);
}

void			destroy_image(void)
{
	mlx_destroy_image(g_application->mlx_ptr, g_application->img_ptr);
	g_application->pixels = NULL;
}

void			free_application(void)
{
	destroy_application();
	free(g_application);
}
