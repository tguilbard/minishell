/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_list_destructors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:18:38 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/11 16:20:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void			destroy_t_vector2_list(t_vector2_list to_delete)
{
	size_t i;
	size_t nb_line;

	nb_line = to_delete.max_size / to_delete.push_size;
	i = 0;
	while (i < nb_line)
	{
		free(to_delete.data[i]);
		i++;
	}
	free(to_delete.data);
}

void			free_t_vector2_list(t_vector2_list *to_free)
{
	destroy_t_vector2_list(*to_free);
	free(to_free);
}

void			t_vector2_list_clear(t_vector2_list *list)
{
	list->size = 0;
}
