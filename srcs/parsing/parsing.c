/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:29:30 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/12 13:03:11 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

/*
**	Erase the simple and the double quotes of the params
*/

static t_param	*quotes_parsing(t_param *tab)
{
	size_t	i;
	size_t	j;
	size_t	n;

	n = 0;
	while (tab->param[n])
	{
		i = 0;
		while (tab->param[n][i])
		{
			j = 0;
			while (tab->param[n][i][j])
			{
				if (tab->param[n][i][j] == 39)
				{
					tab->param[n][i] = rm_quote(tab->param[n][i], "simple");
					break ;
				}
				else if (tab->param[n][i][j] == '\"')
				{
					tab->param[n][i] = rm_quote(tab->param[n][i], "double");
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

static t_param	*replace_environ(t_param *res)
{
	t_rep_env_data	info;

	info = create_rep_env_data();
	while (res->param[info.n])
	{
		info.i = 0;
		while (res->param[info.n][info.i])
		{
			info.j = 0;
			info.raw_text = is_raw(res->param[info.n], info);
			while (res->param[info.n][info.i] && res->param[info.n][info.i][info.j])
				if (res->param[info.n][info.i][info.j] == '$'
							&& ft_is_alpha_num(res->param[info.n][info.i][info.j + 1])
							&& info.raw_text == false)
					put_env_to_text(res->param, &info);
				else if (res->param[info.n][info.i][info.j] == 39
					&& res->param[info.n][info.i][info.j + 1] && info.raw_text == true)
				{
					info.j++;
					while (res->param[info.n][info.i][info.j + 1]
									&& res->param[info.n][info.i][info.j + 1] != 39)
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

t_param		*get_param(char *param)
{
	t_param			*r_param;
	char			***result;
	size_t			i;
	size_t			n;
	size_t			start;

	r_param = malloc_param();
	i = 0;
	n = 0;
	result = (char ***)ft_tab_new(0);
	ft_add_to_tab(ft_tab_new(0), (void ***)&result);
	while (param[i])
	{
		while (param[i] && ft_is_whitespaces(param[i]))
			i++;
		start = i;
		while (param[i] && param[i] != ';' && param[i] != '>' && ft_is_whitespaces(param[i]) == false)
		{
			jump_quotes(param, &i);
		}
		ft_add_to_tab((void*)ft_strsub(param, start, i - start), (void ***)&result[n]);
		if (param[i] == ';' || param[i] == '>')
		{
			i += redirection(param + i);
			ft_add_to_tab(ft_tab_new(0), (void ***)&result);
			n++;
		}
	}
	r_param->param = result;
	return (replace_environ(r_param));
}
