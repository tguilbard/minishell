/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_param.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:09:18 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/12 12:43:25 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARAM_H
# define MINISHELL_PARAM_H

typedef struct		s_param
{
 	char			***param;
 	char			**name;
 	unsigned char	*sep;
}					t_param;

t_param		create_param(void);
void		set_data_param(t_param *param, char ***p_param, char **p_name,
 														unsigned char *p_sep);
t_param		*malloc_param(void);
void		destroy_param(t_param p_param);
void		free_param(t_param *p_param);

#endif
