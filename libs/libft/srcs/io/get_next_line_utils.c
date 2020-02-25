/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:52:50 by ldutriez          #+#    #+#             */
/*   Updated: 2019/12/16 11:56:24 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rm_line(char *bucket)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (bucket[i] && bucket[i] != '\n')
		i++;
	if (!bucket[i])
	{
		free(bucket);
		return (0);
	}
	if (!(str = malloc(sizeof(char) * (ft_slen_eol(bucket, STRLEN) - i + 1))))
		return (0);
	i++;
	while (bucket[i])
	{
		str[j] = bucket[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(bucket);
	return (str);
}

int		ft_slen_eol(const char *str, int use)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (use == STRLEN)
	{
		while (str[i])
			i++;
		return (i);
	}
	else if (use == EOL)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
		return (0);
	}
	return (IS_AN_ERROR);
}

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	char	*d;
	char	*s;

	if (dst == src)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (s > d)
		while (len--)
			*d++ = *s++;
	else if (s < d)
		while (len--)
			*(d + len) = *(s + len);
	return (dst);
}

char	*ft_stradd(char const *bucket, char const *cup)
{
	char			*str;
	unsigned int	n;

	if (!bucket && !cup)
		return (0);
	n = (ft_slen_eol(bucket, STRLEN) + ft_slen_eol(cup, STRLEN) + 1);
	if (!(str = (char*)malloc(sizeof(char) * n)))
		return (0);
	ft_memmove(str, bucket, ft_slen_eol(bucket, STRLEN));
	ft_memmove(str + ft_slen_eol(bucket, STRLEN),
		cup, ft_slen_eol(cup, STRLEN));
	str[ft_slen_eol(bucket, STRLEN) + ft_slen_eol(cup, STRLEN)] = '\0';
	free((void*)bucket);
	return (str);
}

char	*ft_makeline(char *bucket)
{
	int		i;
	char	*str;

	i = 0;
	while (bucket[i] && bucket[i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (bucket[i] && bucket[i] != '\n')
	{
		str[i] = bucket[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
