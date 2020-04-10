/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_param.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:09:18 by ldutriez          #+#    #+#             */
/*   Updated: 2020/04/10 16:10:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARAM_H
# define MINISHELL_PARAM_H

typedef struct	s_param
{
	char	***param;
	char	***name;
	char	***sep;
}				t_param;

t_param			create_param(void);
t_param			*malloc_param(void);
void			add_new_space(t_param *result);
void			destroy_param(t_param p_param);
void			free_param(t_param *p_param);

#endif
