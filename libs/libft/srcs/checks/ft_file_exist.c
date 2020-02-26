/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:44:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/25 20:47:52 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_file_exist(char *p_path)
{
	int	fd;

	fd = open(p_path, O_RDONLY);
	if (fd == -1)
	{
		printf("fd de merde %s", p_path);
		return (false);
	}
	close(fd);
	printf("tranquille frere");
	return (true);
}
