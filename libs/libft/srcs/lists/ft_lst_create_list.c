/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:14:12 by ldutriez          #+#    #+#             */
/*   Updated: 2019/12/11 11:23:47 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_create_list(void *p_data)
{
	t_list	*node;

	node = (void*)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = p_data;
	node->next = NULL;
	return (node);
}
