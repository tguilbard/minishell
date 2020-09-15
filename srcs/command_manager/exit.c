/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:58:31 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/15 16:52:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_ret;
extern int g_env_fd[2];

int	mini_exit(char **p_param)
{
	int i;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	ft_putstr("exit\n", 1);
	if (p_param == NULL || p_param[1] == NULL)
		ft_putnbr(g_ret, g_env_fd[1]);
	else if (p_param[2] != NULL)
	{
		ft_putstr("exit: too many argument\n", 2);
		child_killer(1);
	}
	else
	{
		i = 0;
		while (p_param[1][i] && ft_is_alpha(p_param[1][i]) == false)
			i++;
		if (p_param[1][i])
		{
			ft_putstr("exit: ", 2);
			ft_putstr(p_param[1], 2);
			ft_putstr(": numeric argument required\n", 2);
			ft_putstr("2", g_env_fd[1]);
		}
		else
			ft_putstr(p_param[1], g_env_fd[1]);
	}
	close(g_env_fd[1]);
	exit(0);
}
