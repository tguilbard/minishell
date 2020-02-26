/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_creators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:08:17 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/27 11:29:40 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_color	create_color(unsigned char p_r, unsigned char p_g, unsigned char p_b,
															unsigned char p_a)
{
	t_color result;

	result.r = p_r;
	result.g = p_g;
	result.b = p_b;
	result.a = p_a;
	return (result);
}

t_color	*malloc_color(unsigned char p_r, unsigned char p_g, unsigned char p_b,
															unsigned char p_a)
{
	t_color *result;

	result = (t_color *)malloc(sizeof(t_color));
	if (result == NULL)
		error_exit(9);
	*result = create_color(p_r, p_g, p_b, p_a);
	return (result);
}
