/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:51:20 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/09 15:59:49 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

void	mini_exec(char **p_param)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(p_param[0], p_param, g_env.data) == -1)
			ft_putstr("invalide executable");
	}
	else
		waitpid(pid, NULL, 0);
}
