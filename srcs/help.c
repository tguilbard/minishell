/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:23:47 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/02 11:23:23 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	help(void)
{
	char	*line;
	int		fd;
	size_t	size;

	fd = open("README.md", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		size = ft_strlen(line);
		write(1, line, size);
		write(1, "\n", 1);
		free(line);
	}
	size = ft_strlen(line);
	write(1, line, size);
	write(1, "\n", 1);
	free(line);
	close(fd);
}
