/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:09:12 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/13 13:13:08 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

int		color_int(t_color p_color)
{
	int result;

	result = 0;
	result += p_color.r;
	result += p_color.g;
	result += p_color.b;
	return (result);
}

void	print_color(char *name, t_color color)
{
	char *tmp;

	lgl_putstr(name);
	lgl_putstr(" : ");
	tmp = color_str(color);
	lgl_putstr(tmp);
	free(tmp);
	lgl_putchar('\n');
}

char	*color_str(t_color color)
{
	char *result;
	char *tmp;

	result = lgl_strdup("(");
	tmp = itoa((int)(color.r));
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, " / ");
	tmp = itoa((int)(color.g));
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, " / ");
	tmp = itoa((int)(color.b));
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, " / ");
	tmp = itoa((int)(color.a));
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, ")");
	return (result);
}

t_color	fuze_color(t_color actual, t_color delta)
{
	t_color	result;
	float	base_alpha;
	float	inv_alpha;

	base_alpha = delta.a / 255.0f;
	inv_alpha = 1.0f - base_alpha;
	result.r = base_alpha * delta.r + inv_alpha * actual.r;
	result.g = base_alpha * delta.g + inv_alpha * actual.g;
	result.b = base_alpha * delta.b + inv_alpha * actual.b;
	result.a = 255;
	return (result);
}
