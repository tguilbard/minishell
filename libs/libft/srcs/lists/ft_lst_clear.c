/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:47:03 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/25 11:13:35 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_clear(t_list **lst, void (*del)(void*))
{
	t_list *l;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		l = *lst;
		(*del)(l->data);
		*lst = l->next;
		free(l);
	}
	l = NULL;
	lst = NULL;
}
