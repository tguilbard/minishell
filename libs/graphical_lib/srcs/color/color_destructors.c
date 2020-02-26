/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_destructors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:08:50 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 13:09:07 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void	destroy_color(t_color color)
{
	(void)color;
}

void	free_color(t_color *color)
{
	destroy_color(*color);
	free(color);
}
