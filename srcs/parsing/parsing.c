/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:29:30 by tguilbar          #+#    #+#             */
/*   Updated: 2020/09/15 11:25:16 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

/*
**	Erase the simple and the double quotes of the params
*/

static void		quotes_parsing_loop(t_param *tab, size_t n, size_t i, size_t j)
{
	while (tab->param[n][i][j])
		if (tab->param[n][i][j] == '\\')
		{
			tab->param[n][i] = ft_erase_str(tab->param[n][i], j, 1);
			j += (tab->param[n][i][j] == '\0') ? 0 : 1;
		}
		else if (tab->param[n][i][j] == '\'')
		{
			tab->param[n][i] = ft_erase_str(tab->param[n][i], j, 1);
			while (tab->param[n][i][j] && tab->param[n][i][j] != '\'')
				j++;
		}
		else if (tab->param[n][i][j] == '\"')
		{
			tab->param[n][i] = ft_erase_str(tab->param[n][i], j, 1);
			while (tab->param[n][i][j] && tab->param[n][i][j] != '\"')
			{
				if (tab->param[n][i][j] == '\\')
					tab->param[n][i] = ft_erase_str(tab->param[n][i], j, 1);
				j++;
			}
		}
		else
			j++;
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
			quotes_parsing_loop(tab, n, i, 0);
			i++;
		}
		n++;
	}
	return (tab);
}

static void		replace_environ_forest(t_param *res, t_rep_env_data *info)
{
	if (res->param[info->n][info->i][info->j] == '\\')
	{
		info->j += (res->param[info->n][info->i][info->j + 1] == '\0') ? 1 : 2;
	}
	else if (res->param[info->n][info->i][info->j] == '$'
			&& (ft_is_alpha_num(res->param[info->n][info->i][info->j + 1])
			|| res->param[info->n][info->i][info->j + 1] == '?'))
		put_env_to_text((&res->param[info->n]), info);
	else if (res->param[info->n][info->i][info->j] == '\''
			&& res->param[info->n][info->i][info->j + 1]
			&& info->raw_text == true)
	{
		info->j++;
		while (res->param[info->n][info->i][info->j + 1]
				&& res->param[info->n][info->i][info->j + 1] != '\'')
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
			if (res->param[info.n][info.i])
				info.i++;
		}
		info.n++;
	}
	return (quotes_parsing(res));
}
