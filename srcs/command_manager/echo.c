/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:57:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/05 12:21:53 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

void	mini_echo(char **p_param)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", p_param - 1, g_env.data) == -1)
			perror("minishell");
	}
	else
		wait(NULL);
}
