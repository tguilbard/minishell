/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:57:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/11 13:38:11 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

int	mini_echo(char **p_param)
{
	int		pid;
	int		status;

	pid = fork();
	status = 0;
	if (pid == 0)
	{
		if (execve("/bin/echo", p_param, g_env.data) == -1)
		{
			ft_putstr("echo: invalide param", 2);
			return (1);
		}
	}
	else
		waitpid(pid, &status, 0);
	return (status);
}
