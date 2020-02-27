/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_inf_char_list.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 02:19:30 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/27 02:21:40 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INF_CHAR_LIST_H
# define LIBFT_INF_CHAR_LIST_H

typedef struct	s_char_list
{
	char		**data;
	size_t		size;
}				t_char_list;

char			**ft_chartab_new(size_t nb);
t_char_list		create_char_list(size_t p_size);
t_char_list		*malloc_char_list(size_t p_push_size);
void			destroy_t_char_list(t_char_list to_delete);
void			free_t_char_list(t_char_list *to_free);
void			ft_chartab_cpy(char **old, char **new);
void			ft_char_list_push_back(t_char_list *list, char *to_add);
void			ft_char_list_rm(t_char_list *list, char *to_rm);

#endif
