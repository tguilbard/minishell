/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:21:26 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 13:47:44 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTURES_H
# define LIBFT_STRUCTURES_H

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

#endif
