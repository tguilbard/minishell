/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:33:11 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 13:34:34 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LGL_LIST_H
# define LGL_LIST_H

typedef struct	s_vector2_list
{
	t_vector2	**data;
	size_t		size;
	size_t		max_size;
	size_t		push_size;
}				t_vector2_list;

t_vector2		**lgl_t_vector2tab_new(size_t nb);
t_vector2		*lgl_t_vector2array_new(size_t nb);
void			lgl_t_vector2tab_cpy(t_vector2 **old, t_vector2 **new);
size_t			t_vector2_list_calc_line(t_vector2_list *list, size_t index);
size_t			t_vector2_list_calc_elem(t_vector2_list *list, size_t index);
t_vector2_list	create_t_vector2_list(size_t p_push_size);
t_vector2_list	*malloc_t_vector2_list(size_t p_push_size);
void			destroy_t_vector2_list(t_vector2_list to_delete);
void			free_t_vector2_list(t_vector2_list *to_free);
void			t_vector2_list_push_back(t_vector2_list *list,
															t_vector2 to_add);
t_vector2		t_vector2_list_at(t_vector2_list *list, size_t index);
void			t_vector2_list_clear(t_vector2_list *list);
void			print_vector2_list(t_vector2_list *list);
#endif
