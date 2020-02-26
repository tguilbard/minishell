/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:05:06 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/26 20:17:08 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_char_list	g_env;

void	set_environ(char **env)
{
	size_t	i;
	size_t	len;

	len = ft_tab_len((void**)env);
	g_env = create_char_list(len);
	i = 0;
	while (i < len)
	{
		ft_char_list_push_back(&g_env, ft_strdup(env[i]));
		i++;
	}
}
