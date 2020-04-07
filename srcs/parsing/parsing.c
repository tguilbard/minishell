/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:29:30 by tguilbar          #+#    #+#             */
/*   Updated: 2020/04/07 19:08:51 by anonymous        ###   ########.fr       */
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
							&& (ft_is_alpha_num(res->param[info.n][info.i][info.j + 1])
							|| res->param[info.n][info.i][info.j + 1] == '?')
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

int			take_name(char *param, t_param *result, int n)
{
	int i;
	int start;

	i = 0;
	while (param[i] != '\0' && (ft_is_whitespaces(param[i]) || (param[i] == '>'
									&& i < 2) || (param[i] == '<' && i < 1)))
		i++;
	start = i;
	while (param[i] != '\0' && !ft_is_whitespaces(param[i]) && param[i] != '|'
					&& param[i] != '<' && param[i] != '>' && param[i] != ';')
		i++;
	if (start == i)
	{
		ft_putstr("syntax error near unexpected token `", 2);
		ft_putchar(param[start], 2);
		ft_putstr("'\n", 2);
		child_killer(1);
	}
	ft_add_to_tab(ft_strsub(param, start, i - start), (void ***)&result->name[n]);
	return (i);
}

int			no_name(t_param *result, int n)
{
	ft_add_to_tab(ft_strdup("random"), (void ***)&result->name[n]);
	return (1);
}

void		ft_get_redirection(char *param, size_t *i, t_param *result, int n)
{
	char *sep;

	//foret de if a ranger dans une fonction et remplacer les strnstr pour trouver erreur de sep
	if (ft_strnstr(param + *i, ">>", 2))
		sep = ft_strdup(">>");
	else if (param[*i] == '>')
			sep = ft_strdup(">");
	else if (param [*i] == '<')
		sep = ft_strdup("<");
	ft_add_to_tab(sep, (void ***)&result->sep[n]);
	if (param[*i] == '>' || param[*i] == '<')
		*i += take_name(param + *i, result, n);
	else
		*i += no_name(result, n);
}

t_param		*get_param(char *param)
{
	t_param			*result;
	size_t			i;
	size_t			n;
	size_t			start;

	result = malloc_param();
	i = 0;
	n = 0;
	add_new_space(result);
	while (param[i])
	{
		while (param[i] && ft_is_whitespaces(param[i]))
			i++;
		start = i;
		while (param[i] && param[i] != ';' && param[i] != '>' && param[i] != '<'
					&& param[i] != '|' && ft_is_whitespaces(param[i]) == false)
		{
			jump_quotes(param, &i);
		}
		ft_add_to_tab((void*)ft_strsub(param, start, i - start), (void ***)&result->param[n]);
		if (param[i] == '>' || param[i] == '<')
		{
			if (result->param[n][0])
				ft_get_redirection(param, &i, result, n);
			else
			{
				if (param[i] == '>')
					ft_putstr("syntax error near unexpected token `>'\n", 2);
				else
					ft_putstr("syntax error near unexpected token `<'\n", 2);
				child_killer(1);
			}
		}
		if (param[i] == ';')
		{
			if (result->param[n][0])
			{
				add_new_space(result);
				i++;
				n++;
			}
			else
			{
				ft_putstr("syntax error near unexpected token `;'\n", 2);
				child_killer(1);
			}
		}
		if (param[i] == '|')
		{
			if (result->param[n][0])
			{
				ft_add_to_tab(ft_strdup("|"), (void ***)&result->sep[n]);
				ft_add_to_tab(ft_strdup("random"), (void ***)&result->name[n]);
				add_new_space(result);
				i++;
				n++;
			}
			else
			{
				ft_putstr("syntax error near unexpected token `|'\n", 2);
				child_killer(1);
			}
		}
	}
	return (replace_environ(result));
}
