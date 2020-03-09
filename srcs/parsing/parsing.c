/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:29:30 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/09 15:08:32 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

/*
**	Erase the simple and the double quotes of the params
*/

static char		***quotes_parsing(char ***tab)
{
	size_t	i;
	size_t	j;
	size_t	n;

	n = 0;
	while (tab[n])
	{
		i = 0;
		while (tab[n][i])
		{
			j = 0;
			while (tab[n][i][j])
			{
				if (tab[n][i][j] == 39)
				{
					tab[n][i] = rm_quote(tab[n][i], "simple");
					break ;
				}
				else if (tab[n][i][j] == '\"')
				{
					tab[n][i] = rm_quote(tab[n][i], "double");
					break ;
				}
				j++;
			}
			i++;
		}
		n++;
	}
	return (tab);
}

/*
**	Replace a $word by an env var
*/

static char		***replace_environ(char ***res)
{
	t_rep_env_data	info;

	info = create_rep_env_data();
	while (res[info.n])
	{
		info.i = 0;
		while (res[info.n][info.i])
		{
			info.j = 0;
			info.raw_text = is_raw(res[info.n], info);
			while (res[info.n][info.i] && res[info.n][info.i][info.j])
				if (res[info.n][info.i][info.j] == '$'
							&& ft_is_alpha_num(res[info.n][info.i][info.j + 1])
							&& info.raw_text == false)
					put_env_to_text(res, &info);
				else if (res[info.n][info.i][info.j] == 39
					&& res[info.n][info.i][info.j + 1] && info.raw_text == true)
				{
					info.j++;
					while (res[info.n][info.i][info.j + 1]
									&& res[info.n][info.i][info.j + 1] != 39)
						info.j++;
					info.j++;
				}
				else
					info.j++;
			info.i++;
		}
		info.n++;
	}
	return (quotes_parsing(res));
}

/*
**	Split into multi param
*/

char			***get_param(char *param)
{
	char	***result;
	size_t	i;
	size_t	n;
	size_t	start;

	i = 0;
	n = 0;
	result = (char ***)ft_tab_new(0); // Nan mais t'inquiète j'avais la flemme de recoder un ft_tab_of_tab_new
	ft_add_to_tab(ft_tab_new(0), (void ***)&result);
	while (param[i])
	{
		while (param[i] && ft_is_whitespaces(param[i]))
			i++;
		start = i;
		while (param[i] && param[i] != ';' && ft_is_whitespaces(param[i]) == false)
		{
			jump_quotes(param, &i);
		}
		ft_add_to_tab((void*)ft_strsub(param, start, i - start), (void ***)&result[n]);
		if (param[i] == ';')
		{
			ft_add_to_tab(ft_tab_new(0), (void ***)&result);
			n++;
			i++;
		}
	}
	result[n + 1] = NULL;
	return (replace_environ(result));
}
