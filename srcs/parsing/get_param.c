/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 21:59:32 by user42            #+#    #+#             */
/*   Updated: 2020/09/18 10:07:21 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		get_param_redi(char *param, t_param *result, size_t *i,
																	size_t *n)
{
	if (param[*i] == '>' || param[*i] == '<')
		ft_get_redirection(param, i, result, *n);
}

static void		get_param_sepa(char *param, t_param *result, size_t *i,
																	size_t *n)
{
	if (param[*i] == ';')
	{
		if (result->param[*n][0])
		{
			add_new_space(result);
			(*i)++;
			(*n)++;
		}
		else
		{
			ft_putstr_fd("syntax error near unexpected token «;»\n", 2);
			child_killer(1);
		}
	}
}

static void		get_param_pipe(char *param, t_param *result, size_t *i,
																	size_t *n)
{
	if (param[*i] == '|')
	{
		if (result->param[*n][0])
		{
			ft_add_to_tab(ft_strdup("|"), (void ***)&result->sep[*n]);
			ft_add_to_tab(ft_strdup("random"), (void ***)&result->name[*n]);
			add_new_space(result);
			(*i)++;
			(*n)++;
		}
		else
		{
			ft_putstr_fd("syntax error near unexpected token «|»\n", 2);
			child_killer(1);
		}
	}
}

t_param			*get_param(char *param)
{
	t_param			*result;
	size_t			i;
	size_t			n;
	size_t			start;

	result = malloc_param();
	i = 0;
	n = 0;
	while (param[i])
	{
		while (param[i] && ft_is_whitespaces(param[i]))
			i++;
		start = i;
		while (param[i] && param[i] != ';' && param[i] != '>' && param[i] != '<'
				&& param[i] != '|' && ft_is_whitespaces(param[i]) == false)
			jump_quotes(param, &i);
		ft_add_to_tab((void*)ft_strsub(param, start, i - start),
				(void ***)&result->param[n]);
		get_param_redi(param, result, &i, &n);
		get_param_sepa(param, result, &i, &n);
		get_param_pipe(param, result, &i, &n);
		add_new_space(result);
	}
	return (replace_environ(result));
}
