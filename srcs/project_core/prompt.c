/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:52:27 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/18 10:04:40 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;
extern int			g_env_fd[2];
extern int			g_ret;

static char	*get_usr(void)
{
	char	*result;
	int		index;

	index = find_env_var("USER");
	if (index != -1)
	{
		result = ft_strdup(g_env.data[index] + 5);
		return (result);
	}
	return (ft_strdup("unknow"));
}

static int	ft_put_rainbow_inc(char *str, int i, int len)
{
	int		j;

	j = 0;
	while (j < (int)(len / 7) + 1)
	{
		write(1, str + i + j, 1);
		j++;
		if (!str[i + j])
			break ;
	}
	return (j);
}

static void	ft_put_rainbow(char *str)
{
	char	*format;
	size_t	i;
	size_t	len;
	int		color;

	i = 0;
	color = 91;
	len = ft_strlen(str);
	while (str[i])
	{
		format = ft_itoa(color);
		ft_str_add_prefixe("\033[1;", &format);
		ft_str_add_suffix(&format, "m");
		ft_putstr_fd(format, 1);
		i += ft_put_rainbow_inc(str, i, len);
		ft_putstr_fd("\033[0m", 1);
		if (color == 97)
			color = 91;
		else
			color++;
		free(format);
	}
}

void		print_prompt(void)
{
	int		i;
	int		last;
	char	*str[2];

	str[0] = get_pwd();
	i = 0;
	last = 0;
	while (str[0][i])
	{
		if (str[0][i] == '/')
			last = i;
		i++;
	}
	str[1] = ft_strsub(str[0], last, i - last);
	free(str[0]);
	ft_putstr_fd("\033[3;94m", 1);
	ft_putstr_fd(str[1], 1);
	free(str[1]);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd(" ", 1);
	str[0] = get_usr();
	ft_str_add_prefixe("(", &str[0]);
	ft_str_add_suffix(&str[0], "):");
	ft_put_rainbow(str[0]);
	free(str[0]);
}
