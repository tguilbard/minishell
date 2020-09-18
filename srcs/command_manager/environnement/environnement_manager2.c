/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement_manager2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:14:34 by tguilbar          #+#    #+#             */
/*   Updated: 2020/09/18 10:06:32 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

int		mini_env(char **p_param)
{
	size_t	i;

	i = 0;
	if (p_param[1] != NULL)
	{
		ft_putstr_fd("env: too many argument\n", 2);
		child_killer(1);
	}
	while (g_env.data[i] != NULL)
	{
		ft_putstr_fd(g_env.data[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	return (0);
}

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
