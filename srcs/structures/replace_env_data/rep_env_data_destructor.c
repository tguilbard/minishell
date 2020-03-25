/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_env_data_destructor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:29:01 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/04 13:45:01 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_rep_env_data(t_rep_env_data p_info)
{
	(void)p_info;
}

void	free_rep_env_data(t_rep_env_data *p_info)
{
	destroy_rep_env_data(*p_info);
	free(p_info);
}
