/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:57:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/02 18:26:08 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

void	mini_echo(char *p_str)
{
	int		pid;
	char	*param[2];

	param[0] = p_str;
	param[1] = 0;
	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", param - 1, NULL) == -1)
			perror("minishell");
	}
	else
		wait(NULL);
}
