/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:23:47 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/06 16:30:54 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	help()
{
	char	*line;
	int		fd;
	size_t	size;

	fd = open("README.md", O_RDONLY);
	while(get_next_line(fd, &line) == 1)
	{
		size = ft_strlen(line);
		write(1, line, size);
		write(1, "\n", 1);
	}
}
