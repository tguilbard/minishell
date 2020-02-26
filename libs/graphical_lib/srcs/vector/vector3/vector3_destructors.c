/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_destructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:37:42 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:42:54 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void	destroy_vector3(t_vector3 vector)
{
	(void)vector;
}

void	free_vector3(t_vector3 *vector)
{
	destroy_vector3(*vector);
	free(vector);
}
