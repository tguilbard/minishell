/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_destructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:07:13 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/20 12:20:42 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    destroy_elem(t_elem to_destroy)
{
	(void)to_destroy;
}

void    free_elem(t_elem *to_free)
{
	destroy_elem(*to_free);
	free(to_free);
}
