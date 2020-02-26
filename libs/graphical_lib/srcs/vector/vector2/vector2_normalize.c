/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:13:02 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:27:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_vector2	normalize_vector2(t_vector2 p_vector)
{
	float	norme;

	norme = sqrt(pow(p_vector.x, 2) + pow(p_vector.y, 2));
	p_vector.x /= norme;
	p_vector.y /= norme;
	return (p_vector);
}
