/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:07:45 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/22 11:56:48 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char **environ;

static void	prompt(char *prompt)
{
	write(1, prompt, ft_strlen(prompt));
}

static char	*find_user(char **env)
{
	int i;

	i = 0;
	while(env[i])
	{
		if (take_env_variable("USER", env[i]))
			return(ft_strjoin(((env[i]) + 5), ":"));
		i++;
	}
	return ("unknow:");
}

void		draw_parsing(t_elem **tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		printf("%d | %s\n", tab[i]->type, tab[i]->info);
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

t_elem	**realloc_tab(t_elem **tab)
{
	static size_t	j = 0;
	size_t			i;
	t_elem			**result;

	if (tab == NULL)
		j = 0;
	j++;
	result = malloc(sizeof(t_elem*) * ((j * 3) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		result[((j - 1) * 3) + i] = NULL;
		i++;
	}
	i = 0;
	while (tab && tab[i])
	{
		result[i] = tab[i];
		i++;
	}
	free(tab);
	return (result);
}

void	parse_buffer(char *buffer)
{
	size_t	i;
	t_elem	**tab;

	i = 0;
	tab = NULL;
	while (buffer[i])
	{
		tab = realloc_tab(tab);	
		while (buffer[i] && buffer[i] == ' ')
			i++;
		tab = check_command(tab, buffer + i);
		while (buffer[i] && ((buffer[i] >= 97 && buffer[i] <= 122) ||
					(buffer[i] >= 65 && buffer[i] <= 90)))
			i++;
		if (buffer[i])
			i++;
	}
	draw_parsing(tab);
}

int 		main(int ac, char **av, char **env)
{
	char *buffer;
	char *user;
	
	user = find_user(env);
	prompt(user);
	while (get_next_line(0, &buffer) > 0)
	{
		parse_buffer(buffer);
		prompt(user);
	}
	write(1, "exit\n", 5);
	exit(0) ;
}
