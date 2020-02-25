/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commande.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:46:38 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/25 09:14:22 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *g_command[] ={"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};

t_bool	take_command(char *p_src, char *p_target)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = '\0';
	if (p_src == NULL || p_target == NULL)
		return (0);
	while (p_target[j] != ' ' && p_target[j])
		j++;
	if (p_target[j] == ' ')
	{
		c = ' ';
		p_target[j] = '\0';
	}
	while (p_src[i] != '\0' || p_target[i] != '\0')
	{
		if (p_src[i] != p_target[i])
		{
			p_target[j] = c;
			return (false);
		}
		i++;
	}
	p_target[j] = c;
	return (true);
}

t_bool	take_env_variable(char *p_src, char *p_target)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = '\0';
	if (p_src == NULL || p_target == NULL)
		return (0);
	while (p_target[j] != '=' && p_target[j])//alphaumeric + _
		j++;
	if (p_target[j] == '=')
	{
		c = '=';
		p_target[j] = '\0';
	}
	while (p_src[i] != '\0' || p_target[i] != '\0')
	{
		if (p_src[i] != p_target[i])
		{
			p_target[j] = c;
			return (false);
		}
		i++;
	}
	p_target[j] = c;
	return (true);
}

t_elem	**check_command(t_elem **tab, char *buffer)
{
	size_t	i;

	i = 0;
	while (g_command[i])
	{
		if (take_command(g_command[i], buffer))
		{
			tab[0] = malloc_elem(ft_strdup(g_command[i]) , true, 1);
			return (tab);
		}
		i++;
	}
	tab[0] = NULL;
	return (tab);
}

