/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_str1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:50:35 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 12:51:04 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

size_t	lgl_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*lgl_strnew(size_t size)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

void	lgl_stradd_front(char *s1, char **s2)
{
	char	*tmp;
	size_t	new_size;

	tmp = lgl_strdup(*s2);
	free(*s2);
	new_size = 0;
	if (s1)
		new_size += lgl_strlen(s1);
	if (tmp)
		new_size += lgl_strlen(tmp);
	if (!(*s2 = lgl_strnew(new_size)))
		return ;
	lgl_strcpy(*s2, s1);
	lgl_strcat(*s2, tmp);
	free(tmp);
}

void	lgl_stradd_back(char **s1, char *s2)
{
	char	*tmp;
	size_t	new_size;

	tmp = lgl_strdup(*s1);
	free(*s1);
	new_size = 0;
	if (s2)
		new_size += lgl_strlen(s2);
	if (tmp)
		new_size += lgl_strlen(tmp);
	if (!(*s1 = lgl_strnew(new_size)))
		return ;
	lgl_strcpy(*s1, tmp);
	lgl_strcat(*s1, s2);
	free(tmp);
}

char	*lgl_strdup(char *s1)
{
	char	*dest;
	int		i;

	if (!(dest = lgl_strnew(lgl_strlen(s1))))
		error_exit(7);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
