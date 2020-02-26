/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_behavior.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:31:31 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:34:23 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void		print_vector2(char *name, t_vector2 vector)
{
	char *tmp;

	lgl_putstr(name);
	lgl_putstr(" : ");
	tmp = vector2_str(vector);
	lgl_putstr(tmp);
	free(tmp);
	lgl_putchar('\n');
}

char		*vector2_str(t_vector2 vector)
{
	char *result;
	char *tmp;

	result = lgl_strdup("(");
	tmp = ftoa(vector.x, 3);
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, " / ");
	tmp = ftoa(vector.y, 3);
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, ")");
	return (result);
}

float		vector2_distance(t_vector2 p_a, t_vector2 p_b)
{
	float tmp;
	float tmp2;

	tmp = pow(p_b.x - p_a.x, 2);
	tmp2 = pow(p_b.y - p_a.y, 2);
	return ((float)sqrt(tmp + tmp2));
}
