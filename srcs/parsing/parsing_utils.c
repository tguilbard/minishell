/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:59:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/04 13:24:16 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;

void		jump_quotes(char *param, size_t *index)
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

char		*rm_quote(char *p_str, char *type)
{
	char *tmp;

	tmp = p_str;
	if (ft_strcmp(type, "simple"))
		p_str = ft_rm_charset(p_str, "'");
	else if (ft_strcmp(type, "double"))
		p_str = ft_rm_charset(p_str, "'\"'");
	free(tmp);
	return (p_str);
}

/*
**	Check if the word need to be replace by env var or to be write raw
*/

t_bool		is_raw(char **result, t_rep_env_data info)
{
	while (result[info.i][info.j]
												&& result[info.i][info.j] != 39
												&& result[info.i][info.j] != 34)
		info.j++;
	if (result[info.i][info.j] == 39)
		return (true);
	else if (result[info.i][info.j] == 34 || result[info.i][info.j] == 0)
		return (false);
	return (false);
}

/*
**	Error function if the var searched doesn't exist
*/

void		env_var_missing(t_rep_env_data *info)
{
	info->str = ft_strdup(g_env.data[info->ret] + info->len);
	if (info->new != NULL)
	{
		ft_str_add_suffix(&info->new, info->str);
		free(info->str);
	}
	else
		info->new = info->str;
}

/*
**	Find the env line to put instead of the word
*/

void		put_env_to_text(char ***result, t_rep_env_data *info)
{
	info->start = info->j;
	info->len = 1;
	while (ft_is_alpha_num((*result)[info->i][info->j + info->len]))
		info->len++;
	info->str = ft_strsub((*result)[info->i], info->start + 1, info->len - 1);
	info->ret = find_env_var(info->str);
	free(info->str);
	info->new = ft_strsub((*result)[info->i], 0, info->start);
	if (info->ret != -1)
		env_var_missing(info);
	info->str = ft_strdup((*result)[info->i] + info->start + info->len);
	ft_str_add_suffix(&info->new, info->str);
	free(info->str);
	free((*result)[info->i]);
	(*result)[info->i] = info->new;
	if (info->ret != -1)
		info->j = ft_strlen(g_env.data[info->ret])
												- (info->len + 1) + info->start;
}
