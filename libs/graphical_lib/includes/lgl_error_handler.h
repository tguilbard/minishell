/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_error_handler.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:42:29 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 13:42:44 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LGL_ERROR_HANDLER_H
# define LGL_ERROR_HANDLER_H

typedef enum	e_langage
{
	english = 0,
	french = 1,
	spanish = 2
}				t_langage;

void			set_langage(t_langage p_langage);
void			error_exit(int error);

#endif
