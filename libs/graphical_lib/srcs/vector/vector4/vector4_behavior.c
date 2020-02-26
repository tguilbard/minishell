/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4_behavior.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:45:10 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:47:02 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void	print_vector4(char *name, t_vector4 vector)
{
	char *tmp;

	lgl_putstr(name);
	lgl_putstr(" : ");
	tmp = vector4_str(vector);
	lgl_putstr(tmp);
	free(tmp);
	lgl_putchar('\n');
}

char	*vector4_str(t_vector4 vector)
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
	lgl_stradd_back(&result, " / ");
	tmp = ftoa(vector.z, 3);
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, " / ");
	tmp = ftoa(vector.w, 3);
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, ")");
	return (result);
}
