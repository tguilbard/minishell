/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_destructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:30:49 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:31:00 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void		destroy_vector2(t_vector2 vector)
{
	(void)vector;
}

void		free_vector2(t_vector2 *vector)
{
	destroy_vector2(*vector);
	free(vector);
}
