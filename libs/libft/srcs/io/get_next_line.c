/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:59:27 by ldutriez          #+#    #+#             */
/*   Updated: 2019/12/16 11:56:11 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int fd, char **line)
{
	static char	*bucket;
	char		*cup;
	int			line_state;

	line_state = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (IS_AN_ERROR);
	if (!(cup = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (IS_AN_ERROR);
	while (!ft_slen_eol(bucket, EOL) && line_state != IS_AN_END)
	{
		if ((line_state = read(fd, cup, BUFFER_SIZE)) == IS_AN_ERROR)
			return (IS_AN_ERROR);
		cup[line_state] = '\0';
		bucket = ft_stradd(bucket, cup);
	}
	free(cup);
	*line = ft_makeline(bucket);
	bucket = ft_rm_line(bucket);
	if (line_state == IS_AN_END)
		return (IS_AN_END);
	return (IS_A_LINE);
}
