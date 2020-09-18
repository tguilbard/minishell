/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:58:31 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/18 10:05:21 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_ret;
extern int g_env_fd[2];

int	mini_exit(char **p_param)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	ft_putstr_fd("exit\n", 1);
	if (p_param == NULL || p_param[1] == NULL)
		ft_putnbr_fd(g_ret, g_env_fd[1]);
	else if (ft_str_is_only_digit(p_param[1]) == false)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(p_param[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		ft_putstr_fd("2", g_env_fd[1]);
	}
	else if (p_param[2] != NULL)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		child_killer(1);
	}
	else if (ft_str_is_only_digit(p_param[1]) == true)
		ft_putstr_fd(p_param[1], g_env_fd[1]);
	close(g_env_fd[1]);
	exit(0);
}
