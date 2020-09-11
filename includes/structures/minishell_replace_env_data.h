/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_replace_env_data.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:22:55 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/11 14:44:49 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_REPLACE_ENV_DATA_H
# define MINISHELL_REPLACE_ENV_DATA_H

typedef struct	s_rep_env_data
{
	size_t		i;
	size_t		j;
	size_t		n;
	size_t		start;
	size_t		len;
	t_bool		raw_text;
	int			ret;
	char		*str;
	char		*new;
}				t_rep_env_data;

/*
**	Normal behavior functions
*/

t_rep_env_data	create_rep_env_data(void);
t_rep_env_data	*malloc_rep_env_data(void);
void			destroy_rep_env_data(t_rep_env_data p_info);
void			free_rep_env_data(t_rep_env_data *p_info);

/*
**	Parsing functions
*/

void			jump_quotes(char *param, size_t *index);
char			*rm_quote(char *p_str, char *type);
t_bool			is_raw(char **result, t_rep_env_data info);
void			env_var_missing(t_rep_env_data *info);
void			put_env_to_text(char **result, t_rep_env_data *info);

#endif
