/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:52:27 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/25 15:45:52 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_prompt(char *user)
{
	write(1, user, ft_strlen(user));
}

static char	*get_usr(char **env)
{
	char	*result;
	int		index;

	index = 0;
	while (env[index])
	{
		result = strnstr(env[index], "USER=", 5);
		if (result != NULL)
		{
			result = ft_strdup(result + 5);
			return (result);
		}
		index++;
	}
	return (ft_strdup("unknow"));
}

__attribute__((destructor)) void no_crtl(void)
{
		fork();
}

int			main(int ac, char **av, char **env)
{
	char *str;
	char *user;

	user = get_usr(env);
	ft_str_add_suffix(&user, ":");
	print_prompt(user);
	while (get_next_line(0, &str))
	{
		//parsing
		free(str);
		print_prompt(user);
	}
	write(1, "exit\n", 5);
	exit (0);
}
