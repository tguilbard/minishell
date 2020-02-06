/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_roof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:52:38 by ldutriez          #+#    #+#             */
/*   Updated: 2019/12/02 17:17:21 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_i_roof(float p_value)
{
	int			i_value;

	if (p_value == 0)
		return (0);
	i_value = p_value;
	if (p_value < 0)
		return (i_value);
	else
		return (i_value + 1);
}
