/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:57:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/05 20:43:26 by tguilbar         ###   ########.fr       */
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
			ft_putstr("echo: invalide param");
	}
	else
		wait(NULL);
}
