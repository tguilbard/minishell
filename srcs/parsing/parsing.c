/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:29:30 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/05 10:08:02 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

/*
**	Erase the simple and the double quotes of the params
*/

static char		**quotes_parsing(char **tab)
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
				break ;
			}
			else if (tab[i][j] == '\"')
			{
				tab[i] = rm_quote(tab[i], "double");
				break ;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

/*
**	Replace a $word by an env var
*/

static char		**replace_environ(char **res)
{
	t_rep_env_data	info;

	info = create_rep_env_data();
	while (res[info.i])
	{
		info.j = 0;
		info.raw_text = is_raw(res, info);
		while (res[info.i] && res[info.i][info.j])
			if (res[info.i][info.j] == '$'
									&& ft_is_alpha_num(res[info.i][info.j + 1])
									&& info.raw_text == false)
				put_env_to_text(&res, &info);
			else if (res[info.i][info.j] == 39 && res[info.i][info.j + 1]
													&& info.raw_text == true)
			{
				info.j++;
				while (res[info.i][info.j + 1] && res[info.i][info.j + 1] != 39)
					info.j++;
				info.j++;
			}
			else
				info.j++;
		info.i++;
	}
	return (quotes_parsing(res));
}

/*
**	Split into multi param
*/

char			**get_param(char *param)
{
	void	**result;
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
