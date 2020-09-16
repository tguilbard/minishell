/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:58:31 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/16 10:17:19 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_ret;
extern int g_env_fd[2];

int	mini_exit(char **p_param)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	ft_putstr("exit\n", 1);
	if (p_param == NULL || p_param[1] == NULL)
		ft_putnbr(g_ret, g_env_fd[1]);
	else if (ft_str_is_only_digit(p_param[1]) == false)
	{
		ft_putstr("exit: ", 2);
		ft_putstr(p_param[1], 2);
		ft_putstr(": numeric argument required\n", 2);
		ft_putstr("2", g_env_fd[1]);
	}
	else if (p_param[2] != NULL)
	{
		ft_putstr("exit: too many arguments\n", 2);
		child_killer(1);
	}
	else if (ft_str_is_only_digit(p_param[1]) == true)
		ft_putstr(p_param[1], g_env_fd[1]);
	close(g_env_fd[1]);
	exit(0);
}
