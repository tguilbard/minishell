/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:57:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/18 10:05:01 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

int	mini_echo(char **p_param)
{
	int		param_index;
	t_bool	n_flag;

	param_index = 1;
	n_flag = false;
	if (p_param == NULL || p_param[0] == NULL)
		return (-1);
	while (p_param[param_index])
	{
		if (param_index == 1)
			while (ft_strcmp(p_param[param_index], "-n"))
			{
				n_flag = true;
				param_index++;
			}
		ft_putstr_fd(p_param[param_index], 1);
		if (p_param[param_index + 1])
			ft_putchar_fd(' ', 1);
		param_index++;
	}
	if (n_flag == false)
		ft_putchar_fd('\n', 1);
	return (0);
}
