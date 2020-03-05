/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:31:24 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/05 23:05:17 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	strlen2(char *s1, char *s2, int type)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1)
		while (s1[i] && (type == 0 || (type == 1 && s1[i] != '\n')))
			i++;
	if (type == 0)
	{
		while (s2[j])
			j++;
		return (i + j);
	}
	if (!s1)
		return (1);
	else if (s1[i] != '\n')
		return (1);
	return (0);
}

int				check_create(int fd, t_list_gnl **l1)
{
	t_list_gnl	*new;
	t_list_gnl	*lst;

	lst = *l1;
	while (lst)
	{
		if (lst->fd == fd)
			return (0);
		lst = lst->next;
	}
	if (!(new = malloc(sizeof(t_list_gnl))))
		return (-1);
	new->fd = fd;
	new->next = *l1;
	new->stock = NULL;
	*l1 = new;
	return (0);
}

t_list_gnl			*fb(int fd, t_list_gnl **l1)
{
	t_list_gnl *lst;

	lst = *l1;
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void			del_lst(t_list_gnl *l)
{
	free(l->stock);
	l->stock = NULL;
	free(l);
	l = NULL;
}

void			rm_lst(int fd, t_list_gnl **lst)
{
	t_list_gnl *lst1;
	t_list_gnl *lst2;

	if ((*lst)->fd == fd)
	{
		lst1 = *lst;
		*lst = lst1->next;
		del_lst(lst1);
		return ;
	}
	lst1 = *lst;
	lst2 = lst1->next;
	while (lst2->fd != fd)
	{
		if (!lst2)
			return ;
		lst1 = lst2;
		lst2 = lst1->next;
	}
	lst1->next = lst2->next;
	del_lst(lst2);
}
