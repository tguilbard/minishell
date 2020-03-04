/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:29:30 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/04 10:05:47 by ldutriez         ###   ########.fr       */
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

static char *rm_quote(char *p_str, char *type)
{
	char *tmp;

	tmp = p_str;
	if (ft_strcmp(type, "simple"))
		p_str = ft_rm_charset(p_str, "'");
	else if (ft_strcmp(type, "double"))
		p_str = ft_rm_charset(p_str, "\"");
	free(tmp);
	return (p_str);
}

static char	**quotes_parsing(char **tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 39)
			{
				tab[i] = rm_quote(tab[i], "simple");
				break;
			}
			else if (tab[i][j] == '"')
			{
				tab[i] = rm_quote(tab[i], "double");
				break;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
static t_bool	is_raw(t_rep_env_data info)
{

}

static char	**replace_environ(char **result)
{
	t_rep_env_data	info;

	info = create_rep_env_data();
	while (result[info.i])
	{
		info.j = 0;
		while (result[info.i][info.j] && result[info.i][info.j] != 39 && result[info.i][info.j] != 34)
			info.j++;
		if (result[info.i][info.j] == 39)
			info.raw_text = true;
		else if (result[info.i][info.j] == 34 || result[info.i][info.j] == 0)
			info.raw_text = false;
		info.j = 0;
		while (result[info.i] && result[info.i][info.j])
		{
			if (result[info.i][info.j] == '$' && ft_is_alpha_num(result[info.i][info.j + 1]) && info.raw_text == false)
			{
				info.start = info.j;
				info.len = 1;
				while(ft_is_alpha_num(result[info.i][info.j + info.len]))
					info.len++;
				info.str = ft_strsub(result[info.i], info.start + 1, info.len - 1);
				info.ret = find_env_var(info.str);
				free(info.str);
				info.new = ft_strsub(result[info.i], 0, info.start);
				if (info.ret != -1)
				{
					info.str = ft_strdup(g_env.data[info.ret] + info.len);
					if (info.new != NULL)
					{
						ft_str_add_suffix(&info.new, info.str);
						free(info.str);
					}
					else
						info.new = info.str;
				}
				info.str = ft_strdup(result[info.i] + info.start + info.len);
				ft_str_add_suffix(&info.new, info.str);
				free(info.str);
				free(result[info.i]);
				result[info.i] = info.new;
				if (info.ret != -1)
					info.j = ft_strlen(g_env.data[info.ret]) - (info.len + 1) + info.start;
			}
			else if (result[info.i][info.j] == 39 && result[info.i][info.j + 1] && info.raw_text == true)
			{
				info.j++;
				while (result[info.i][info.j + 1] && result[info.i][info.j + 1] != 39)
					info.j++;	//heap buffer overflow car tu peux avamcer trop loin. (info.j'ai rajouté + 1)
							//&& Si pas de deuxieme quote, revenir en arriere pour parser,
							//ou alors ne pas parser la simple quote quand entre double quote <------
				info.j++;
			}
			else
				info.j++;
		}
		info.i++;
	}
	return (quotes_parsing(result));
}

char		**get_param(char *param)
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
	return (replace_environ((char**)result));
}
