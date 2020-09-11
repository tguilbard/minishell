/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:29:30 by tguilbar          #+#    #+#             */
/*   Updated: 2020/09/11 16:42:02 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

/*
**	Erase the simple and the double quotes of the params
*/

static void		quotes_parsing_loop(t_param *tab, size_t n, size_t i)
{
	size_t j;

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
}

t_param			*quotes_parsing(t_param *tab)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (tab->param[n])
	{
		i = 0;
		while (tab->param[n][i])
		{
			quotes_parsing_loop(tab, n, i);
			i++;
		}
		n++;
	}
	return (tab);
}

static void		replace_environ_forest(t_param *res, t_rep_env_data *info)
{
	if (res->param[info->n][info->i][info->j] == '$'
			&& (ft_is_alpha_num(res->param[info->n][info->i][info->j + 1])
				|| res->param[info->n][info->i][info->j + 1] == '?')
			&& info->raw_text == false)
		put_env_to_text(res->param[info->n], info);
	else if (res->param[info->n][info->i][info->j] == 39
			&& res->param[info->n][info->i][info->j + 1] &&
			info->raw_text == true)
	{
		info->j++;
		while (res->param[info->n][info->i][info->j + 1]
				&& res->param[info->n][info->i][info->j + 1] != 39)
			info->j++;
		info->j++;
	}
	else
		info->j++;
}

/*
**	Replace a word by an env var
*/

t_param			*replace_environ(t_param *res)
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
			while (res->param[info.n][info.i] &&
					res->param[info.n][info.i][info.j])
				replace_environ_forest(res, &info);
			info.i++;
		}
		info.n++;
	}
	return (quotes_parsing(res));
}
