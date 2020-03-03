/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:29:30 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/03 20:03:06 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

static void	jump_quotes(char *param, size_t *index)
{
	if (param[*index] == '"')
	{
		(*index)++;
		while (param[*index] != '"' && param[*index])
			(*index)++;
	}
	else if (param[*index] == 39)
	{
		(*index)++;
		while (param[*index] != 39 && param[*index])
			(*index)++;
	}
	if (param[*index])
		(*index)++;
}

char		**check_param(char *param)
{
	void 	**result;
	size_t	index;
	size_t	start;

	result = ft_tab_new(0);
	index = 0;
	while (param[index])
	{
		while (param[index] && ft_is_whitespaces(param[index]))
			index++;
		start = index;
		while (param[index] && ft_is_whitespaces(param[index]) == false)
		{
			jump_quotes(param, &index);
		}
		ft_add_to_tab((void*)ft_strsub(param, start, index - start), &result);
	}
	return ((char**)result);
}

static char	**rm_quotes(char **tab)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 39)
			{
				tmp = tab[i];
				tab[i] = ft_rm_charset(tab[i], "'");
				free(tmp);
				break;
			}
			else if (tab[i][j] == '"')
			{
				tmp = tab[i];
				tab[i] = ft_rm_charset(tab[i], "\"");
				free(tmp);
				break;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

char	**replace_environ(char **result)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	len;
	int		ret;
	char	*str;
	char	*new;

	i = 0;
	while (result[i])
	{
		j = 0;
		while (result[i] && result[i][j])
		{
			if (result[i][j] == '$' && ft_is_alpha_num(result[i][j + 1]))
			{
				start = j;
				len = 1;
				while(ft_is_alpha_num(result[i][j + len]))
					len++;
				str = ft_strsub(result[i], start + 1, len - 1);
				ret = find_env_var(str);
				free(str);
				new = ft_strsub(result[i], 0, start);
				if (ret != -1)
				{
					str = ft_strdup(g_env.data[ret] + len);
					if (new != NULL)
					{
						ft_str_add_suffix(&new, str);
						free(str);
					}
					else
						new = str;
				}
				str = ft_strdup(result[i] + start + len);
				ft_str_add_suffix(&new, str);
				free(str);
				free(result[i]);
				result[i] = new;
				if (ret != -1)
					j = ft_strlen(g_env.data[ret]) - (len + 1) + start;
			}
			else if (result[i][j] == 39)
			{
				j++;
				while (result[i][j] && result[i][j] != 39)
					j++;
				j++;
			}
			else
				j++;
		}
		i++;
	}
	return (rm_quotes(result));
}
