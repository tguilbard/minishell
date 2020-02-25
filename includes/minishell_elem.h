/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_elem.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:48:47 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/24 15:56:58 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ELEM_H
# define MINISHELL_ELEM_H

typedef struct	s_elem
{
	char		*info;
	t_bool		parsing;
	int			type;
}				t_elem;

t_elem			create_elem(char *p_info, t_bool p_paring, int p_type);
t_elem			*malloc_elem(char *p_info, t_bool p_paring, int p_type);
void			destroy_elem(t_elem to_destroy);
void			free_elem(t_elem *to_free);

#endif
