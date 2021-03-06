/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_destructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:02:03 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/11 11:41:05 by ldutriez         ###   ########.fr       */
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
	free(p_param.param);
	free(p_param.sep);
	free(p_param.name);
}

void		free_param(t_param *p_param)
{
	destroy_param(*p_param);
	free(p_param);
}
