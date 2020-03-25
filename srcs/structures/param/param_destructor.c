/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_destructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:02:03 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/25 13:07:39 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		destroy_param(t_param p_param)
{
	size_t	i;

	i = 0;
	while (p_param.param && p_param.param[i])
	{
		ft_free_tab((void**)p_param.param[i]);
		ft_free_tab((void**)p_param.sep[i]);
		ft_free_tab((void**)p_param.name[i]);
		i++;
	}
}

void		free_param(t_param *p_param)
{
	destroy_param(*p_param);
	free(p_param);
}
