/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tguilbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 23:27:35 by user42            #+#    #+#             */
/*   Updated: 2020/04/10 23:37:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_char_list	g_env;
int			g_env_fd[2];
int			g_ret = 0;

int	main(int ac __attribute__((unused)),
								char **av __attribute__((unused)), char **env)
{
	set_environ(env);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	forker();
	return (0);
}
