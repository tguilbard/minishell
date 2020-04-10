/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:34:11 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/04/10 16:15:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_get_file(char *path)
{
	char	**result;
	int		fd;
	char	*line;

	result = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 3)
	{
		printf("%s\n", "Error : Bad fd");
		return (NULL);
	}
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_add_to_tab((void *)line, (void ***)&result);
	}
	close(fd);
	return (result);
}
