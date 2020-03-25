/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement_manager1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:05:06 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/25 00:57:32 by anonymous        ###   ########.fr       */
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

int		check_entry_export(char *p_to_add)
{
	if (ft_is_digit(p_to_add[0]))
	{
		ft_putstr("not a valid identifier\n", 2);
		return (1);
	}
	else if (ft_strcmp_c(p_to_add, '=') == false)
	{}
	else
		return (2);
	return (0);
}

int		mini_export(char **p_to_add)
{
	int	i;
	size_t	j;
	int		ret[2];
	char	*find;

	j = 1;
	ret[1] = 0;
	while (p_to_add[j])
	{
		i = 0;
		ret[0] = check_entry_export(p_to_add[j]);
		if (ret[0] == 0 || ret[0] == 1)
		{}
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
	ret[1] = (ret[1] == 1 || ret[0] == 1) ? 1 : 0;
	return (ret[1]);
}

int		mini_unset(char **p_to_remove)
{
	int	i;
	size_t	j;
	int		ret[2];

	j = 1;
	ret[1] = 0;
	while (p_to_remove[j])
	{
		ret[0] = check_entry_export(p_to_remove[j]);
		if (ret[0] == 1)
			;
		else if ((i = find_env_var(p_to_remove[j])) != -1)
			ft_char_list_rm(&g_env, g_env.data[i]);
		j++;
	}
	ret[1] = (ret[1] == 1 || ret[0] == 1) ? 1 : 0;
	return (ret[1]);
}
