#include "lgl.h"

void	lgl_putchar(char c)
{
	write(1, &c, 1);
}

size_t lgl_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;

	return (i);
}

void	lgl_putstr(char *s)
{
	if (s != NULL)
		write(1, s, lgl_strlen(s));
}

void	lgl_putnbr(int n)
{
	unsigned int nbr;
	unsigned int nb;

	nbr = 0;
	nb = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		nbr = (unsigned int)n * -1;
	}
	else if (n >= 0)
		nbr = (unsigned int)n;
	if (nbr >= 10)
		lgl_putnbr(nbr / 10);
	nb = nbr % 10 + '0';
	write(1, &nb, 1);
}

char *lgl_strnew(size_t size)
{
	char *result;
	size_t i;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		result[i] ='\0';
		i++;
	}
	return (result);
}

char	*itoa(int n)
{
	char			*answer;
	int				i;
	long int		nbr;
	int				minus;

	answer = NULL;
	i = 1;
	nbr = n;
	minus = 0;
	while ((n >= 10 || n <= -10) && i++)
		n /= 10;
	minus = (nbr < 0) ? 1 : 0;
	nbr *= nbr < 0 ? -1 : 1;
	if (!(answer = malloc(sizeof(char) * i + 1 + minus)))
		return (NULL);
	answer[i + minus] = '\0';
	i = (!minus) ? i - 1 : i;
	while (nbr >= 10)
	{
		answer[i--] = nbr % 10 + 48;
		nbr /= 10;
	}
	answer[i] = nbr + 48;
	answer[0] = minus == 1 ? '-' : answer[0];
	return (answer);
}

void		lgl_stradd_front(char *s1, char **s2)
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

void		lgl_stradd_back(char **s1, char *s2)
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

char	*lgl_strdup( char *s1)
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

char		*lgl_strcut(char **src, char c)
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

int convert_2di_1di(t_vector2 pos, t_vector2 size)
{
	return((int)(pos.x) + ((int)(pos.y) * (int)(size.x)));
}

float convert_2d_1d(t_vector2 pos, t_vector2 size)
{
	return(pos.x + (pos.y * size.x));
}
