#include "lgl.h"
void	create_string(float nb, char *rest, int i)
{
	int		afterdots;
	int		dot;

	dot = 0;
	afterdots = 0;
	if (nb < 1)
	{
		rest[i++] = '.';
		dot = i;
		while (afterdots < 2)
		{
			nb *= 10;
			if (((int)(nb + 0.01)) != 10)
				rest[i++] = (int)(nb + 48 + 0.01);
			nb -= (int)nb;
			afterdots++;
		}
	}
	while (i - dot < 2)
		rest[i++] = '0';
	rest[i] = '\0';
}

char	*ftoa(float n, int testi)
{
	char		*flt;
	char		*first;
	long int	nb;
	int			i;
	int			j;

	(void)testi;
	i = -1;
	j = -1;
	nb = (long int)n;
	first = itoa(nb);
	flt = (char *)malloc(100);
	n -= (float)nb;
	if (n < 0)
	{
		n *= -1;
		if (nb == 0)
			flt[++j] = '-';
	}
	while (first[++i])
		flt[++j] = first[i];
	create_string(n, flt, i);
	free(first);
	return (flt);
}
