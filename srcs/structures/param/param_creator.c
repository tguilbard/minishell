/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:56:58 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/12 12:43:10 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_param	create_param(void)
{
	t_param	result;

	result.param = NULL;
	result.name = NULL;
	result.sep = NULL;
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

void		set_data_param(t_param *param, char ***p_param, char **p_name,
													   unsigned char *p_sep)
{
	param->param = p_param;
	param->name = p_name;
	param->sep = p_sep;
}
