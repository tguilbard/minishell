/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_list_creators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:15:16 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:17:37 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_vector2		**lgl_t_vector2tab_new(size_t nb)
{
	t_vector2	**tab;
	size_t		i;

	tab = (t_vector2 **)malloc(sizeof(t_vector2 *) * (nb + 1));
	i = 0;
	while (i <= nb)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}

t_vector2		*lgl_t_vector2array_new(size_t nb)
{
	t_vector2 *array;

	array = (t_vector2 *)malloc(sizeof(t_vector2) * nb);
	return (array);
}

t_vector2_list	create_t_vector2_list(size_t p_push_size)
{
	t_vector2_list result;

	result.size = 0;
	result.push_size = p_push_size;
	result.max_size = result.push_size;
	result.data = lgl_t_vector2tab_new(1);
	result.data[0] = lgl_t_vector2array_new(result.push_size);
	return (result);
}

t_vector2_list	*malloc_t_vector2_list(size_t p_push_size)
{
	t_vector2_list *t_vector2_result;

	t_vector2_result = (t_vector2_list *)malloc(sizeof(t_vector2_list));
	*t_vector2_result = create_t_vector2_list(p_push_size);
	return (t_vector2_result);
}
