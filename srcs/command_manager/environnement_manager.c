/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:05:06 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/26 23:44:21 by ldutriez         ###   ########.fr       */
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

void	mini_export(char *p_to_add)
{
	ft_char_list_push_back(&g_env, ft_strdup(p_to_add));
}

void	mini_unset(char *p_to_remove)
{
	size_t i;

	i = 0;
	while (g_env.data[i] != NULL && i < g_env.size)
	{
		if (ft_strnstr(g_env.data[i], p_to_remove, ft_strlen(p_to_remove)))
		{
			ft_char_list_rm(&g_env, g_env.data[i]);
			return ;
		}
		i++;
	}
}

void	mini_env(void)
{
	size_t	i;

	i = 0;
	while (g_env.data[i] != NULL)
	{
		ft_putstr(g_env.data[i]);
		ft_putchar('\n');
		i++;
	}
}
