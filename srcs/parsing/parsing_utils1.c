/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:59:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/15 11:21:44 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;
extern int			g_ret;

/*
**	Check if the word need to be replace by env var or to be write raw
*/

t_bool		is_raw(char **result, t_rep_env_data info)
{
	while (result[info.i][info.j] != '\0'
										&& result[info.i][info.j] != 39
										&& result[info.i][info.j] != 34)
		info.j++;
	if (result[info.i][info.j] == 39)
		return (true);
	else if (result[info.i][info.j] == 34
										|| result[info.i][info.j] == 0)
		return (false);
	return (false);
}

void		env_replace(t_rep_env_data *info)
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

void		return_val_replace(t_rep_env_data *info)
{
	info->str = ft_itoa(g_ret);
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
	info->ret = -2;
	info->start = info->j;
	info->len = 1;
	while (ft_is_alpha_num((*result)[info->i][info->j + info->len])
		|| (*result)[info->i][info->j + info->len] == '?')
		info->len++;
	info->str = ft_strsub((*result)[info->i], info->start + 1, info->len - 1);
	info->ret = (*(info->str) != '?') ? find_env_var(info->str) : info->ret;
	free(info->str);
	info->new = ft_strsub((*result)[info->i], 0, info->start);
	if (info->ret == -2)
		return_val_replace(info);
	else if (info->ret != -1)
		env_replace(info);
	info->j = ft_strlen(info->new);
	info->str = ft_strdup((*result)[info->i] + info->start + info->len);
	ft_str_add_suffix(&info->new, info->str);
	free(info->str);
	if (info->ret == -1)
		ft_tab_erase((void ***)result, info->i);
	else
	{
		free((*result)[info->i]);
		(*result)[info->i] = info->new;
	}
}
