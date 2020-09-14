/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:57:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/14 13:51:34 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

int	mini_echo(char **p_param)
{
	int		param_index;

	param_index = 1;
	if (p_param == NULL || p_param[0] == NULL)
		return (-1);
	while (p_param[param_index])
	{
		ft_putstr(p_param[param_index], 1);
		if (p_param[param_index + 1])
			ft_putchar(' ', 1);
		param_index++;
	}
	ft_putchar('\n', 1);
	return (0);
}
