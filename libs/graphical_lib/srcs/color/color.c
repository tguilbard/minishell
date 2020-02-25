/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 02:56:55 by ldutriez          #+#    #+#             */
/*   Updated: 2019/12/03 18:39:07 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_color create_color(int p_r, int p_g, int p_b, int p_a)
{
	t_color result;

	result.r = p_r;
	result.g = p_g;
	result.b = p_b;
	result.a = p_a;
	return (result);
}

t_color *malloc_color(int p_r, int p_g, int p_b, int p_a)
{
	t_color *result;

	result = (t_color *)malloc(sizeof(t_color));
	if (result == NULL)
		error_exit(9);

	*result = create_color(p_r, p_g, p_b, p_a);

	return (result);
}

void destroy_color(t_color color)
{
	(void)color;
}

void free_color(t_color *color)
{
	destroy_color(*color);
	free(color);
}

int	color_int(t_color p_color)
{
	int result;

	result = 0;
	result += p_color.r;
	result += p_color.g;
	result += p_color.b;
	return (result);
}

void print_color(char *name, t_color color)
{
	char *tmp;

	lgl_putstr(name);
	lgl_putstr(" : ");

	tmp = color_str(color);
	lgl_putstr(tmp);
	free(tmp);

	lgl_putchar('\n');
}

char *color_str(t_color color)
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
