/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement_manager1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:05:06 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/05 21:38:43 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_char_list	g_env;

int		find_env_var(char *find)
{
	size_t	i;
	size_t	j;
	char	*lst;

	j = 0;
	while (g_env.data[j] && j < g_env.size)
	{
		i = 0;
		while (g_env.data[j][i] != '=' && g_env.data[j][i])
			i++;
		lst = ft_strsub(g_env.data[j], 0, i);
		if (ft_strcmp(lst, find))
		{
			free(lst);
			return (j);
		}
		j++;
		free(lst);
	}
	return (-1);
}

t_bool	check_entry_export(char *p_to_add)
{
	if (ft_is_digit(p_to_add[0]))
		ft_putstr("not a valid identifier\n");
	else if (ft_strcmp_c(p_to_add, '=') == false)
		;
	else
		return (true);
	return (false);
}

void	mini_export(char **p_to_add)
{
	size_t	i;
	size_t	j;
	char	*find;

	j = 0;
	while (p_to_add[j])
	{
		i = 0;
		if (check_entry_export(p_to_add[j]) == false)
			return ;
		while (p_to_add[j][i] != '=' && p_to_add[j][i])
			i++;
		find = ft_strsub(p_to_add[j], 0, i);
		if ((i = find_env_var(find)) != -1)
			ft_char_list_replace(&g_env, g_env.data[i], ft_strdup(p_to_add[j]));
		else
			ft_char_list_push_back(&g_env, ft_strdup(p_to_add[j]));
		free(find);
		j++;
	}
}

void	mini_unset(char **p_to_remove)
{
	size_t i;
	size_t j;

	j = 0;
	while (p_to_remove[j])
	{
		if ((i = find_env_var(p_to_remove[j])) != -1)
		{
			ft_char_list_rm(&g_env, g_env.data[i]);
			return ;
		}
		j++;
	}
}
