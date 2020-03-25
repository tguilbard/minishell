/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:56:58 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/26 00:24:40 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_param	create_param(void)
{
	t_param	result;

	result.param = (char ***)ft_tab_new(0);
	result.name = (char ***)ft_tab_new(0);
	result.sep = (char ***)ft_tab_new(0);
	return (result);
}

t_param	*malloc_param(void)
{
	t_param *result;

	result = (t_param*)malloc(sizeof(t_param));
	if (result == NULL)
		return (NULL);
	*result = create_param();
	return (result);
}

void	add_new_space(t_param *result)
{
	ft_add_to_tab(ft_tab_new(0), (void ***)&result->param);
	ft_add_to_tab(ft_tab_new(0), (void ***)&result->sep);
	ft_add_to_tab(ft_tab_new(0), (void ***)&result->name);
}
