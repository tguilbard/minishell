/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:29:52 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/14 16:46:30 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_erase_str(char *p_str, size_t pos, size_t len)
{
	char	*result;
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(p_str);
	result = ft_strnew(str_len - len);
	while (i < pos)
	{
		result[i] = p_str[i];
		i++;
	}
	while (i < str_len)
	{
		result[i] = p_str[i + len];
		i++;
	}
	result[i] = '\n';
	free(p_str);
	return (result);
}