/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_behavior.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:23:39 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/26 19:46:41 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_chartab_cpy(char **old, char **new)
{
	size_t i;

	i = 0;
	while (old[i] != NULL)
	{
		new[i] = old[i];
		i++;
	}
}

void			ft_char_list_push_back(t_char_list *list, char *to_add)
{
	size_t		i;
	char		**tmp;

	i = 0;
	while (list->data[i] != NULL && i < list->size)
		i++;
	if (i == list->size)
	{
		tmp = list->data;
		list->size += (list->size % 2 == 1) ? 1 : 2;
		list->data = ft_chartab_new(list->size);
		ft_chartab_cpy(tmp, list->data);
		free(tmp);
	}
	list->data[i] = to_add;
}
