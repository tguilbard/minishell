/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4_destructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:45:27 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:47:10 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void	destroy_vector4(t_vector4 vector)
{
	(void)vector;
}

void	free_vector4(t_vector4 *vector)
{
	destroy_vector4(*vector);
	free(vector);
}
