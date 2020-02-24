/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_constructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:01:35 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/22 10:32:59 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_elem  create_elem(char *p_info, t_bool p_parsing, int p_type)
{
	t_elem result;

	result.info = p_info;
	result.parsing = p_parsing;
	result.type = p_type;
	return (result);
}

t_elem  *malloc_elem(char *p_info, t_bool p_paring, int p_type)
{
	t_elem *result;

	result = malloc(sizeof(t_elem));
	if (result == NULL)
		return (NULL);
	*result = create_elem(p_info, p_paring, p_type);
	return (result);
}
