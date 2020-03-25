/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:51:20 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/25 00:57:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

int	mini_exec(char **p_param)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(p_param[0], p_param, g_env.data) == -1)
		{
			ft_putstr("invalide executable\n", 2);
			return (1);
		}
		exit(0);
	}
	else
		waitpid(pid, &status, 0);
	return (status);
}
