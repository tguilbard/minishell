/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_env_data_creator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:28:12 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/04 13:43:39 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_rep_env_data	create_rep_env_data(void)
{
	t_rep_env_data result;

	result.i = 0;
	result.j = 0;
	result.start = 0;
	result.len = 0;
	result.raw_text = false;
	result.ret = 0;
	result.str = NULL;
	result.new = NULL;
	return (result);
}

t_rep_env_data	*malloc_rep_env_data(void)
{
	t_rep_env_data *result;

	result = (t_rep_env_data*)malloc(sizeof(t_rep_env_data));
	if (result == NULL)
		return (NULL);
	*result = create_rep_env_data();
	return (result);
}
