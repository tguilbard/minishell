/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 20:16:30 by user42            #+#    #+#             */
/*   Updated: 2020/09/11 11:04:56 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;
extern int			g_ret;

void	jump_quotes(char *param, size_t *index)
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

/*
**	Remove only the external quote
*/

char	*rm_quote(char *p_str, char *type)
{
	char *tmp;
	char to_del[2];

	to_del[0] = '\"';
	to_del[1] = '\0';
	tmp = p_str;
	if (ft_strcmp(type, "simple"))
		p_str = ft_rm_charset(p_str, "\'");
	else if (ft_strcmp(type, "double"))
		p_str = ft_rm_charset(p_str, to_del);
	free(tmp);
	return (p_str);
}

int		take_name(char *param, t_param *result, int n)
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
	ft_add_to_tab(ft_strsub(param, start, i - start),
			(void ***)&result->name[n]);
	return (i);
}

int		no_name(t_param *result, int n)
{
	ft_add_to_tab(ft_strdup("random"), (void ***)&result->name[n]);
	return (1);
}

void	ft_get_redirection(char *param, size_t *i, t_param *result, int n)
{
	char *sep;

	sep = NULL;
	if (ft_strnstr(param + *i, ">>", 2))
		sep = ft_strdup(">>");
	else if (param[*i] == '>')
		sep = ft_strdup(">");
	else if (param[*i] == '<')
		sep = ft_strdup("<");
	ft_add_to_tab(sep, (void ***)&result->sep[n]);
	if (param[*i] == '>' || param[*i] == '<')
		*i += take_name(param + *i, result, n);
	else
		*i += no_name(result, n);
}
