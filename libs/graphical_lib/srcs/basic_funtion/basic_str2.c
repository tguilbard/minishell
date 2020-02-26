/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:51:43 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 12:52:01 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

char	*lgl_strcat(char *s1, char *s2)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*lgl_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*lgl_strcut(char **src, char c)
{
	size_t		i;
	char		*dest;
	char		*tmp;

	i = 0;
	while ((*src)[i] != '\0' && (*src)[i] != c)
		i++;
	if (i == lgl_strlen(*src))
	{
		dest = lgl_strdup(*src);
		lgl_strclr(*src);
	}
	else
	{
		dest = lgl_strsub(*src, 0, i);
		tmp = (*src);
		*src = lgl_strsub(*src, i + 1, lgl_strlen(*src));
		free(tmp);
	}
	return (dest);
}

char	*lgl_strsub(char *s, unsigned int start, size_t len)
{
	char		*fresh;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(fresh = malloc((len + 1) * sizeof(char))))
		error_exit(8);
	while (len > i)
	{
		fresh[i] = s[start + i];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}

void	lgl_strclr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}
