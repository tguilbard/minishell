/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:49:15 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/11 14:07:45 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(char *str)
{
	size_t i;
	size_t start;

	i = 0;
	while (str[i] == '>' || str[i] == '|' || str[i] == '<')
		i++;
	while (ft_is_whitespaces(str[i]))
		i++;
	start = i;
	while (ft_is_alpha_num(str[i]))
		i++;
	return (ft_strsub(str, start, i - start));
}

int		redirection(char *str)
{
	char	*file;
	char	*name;
	int		fd[2];
	int		ret;
	int		i;

	fd[1] = 0;
	file = NULL;
	ret = 1;
	i = 1;
	name = get_name(str);
	if (*str != ';')
		i += ft_strlen(name);
	if (ft_strnstr(str, ">>", 2))
	{
		i += 1;
		fd[1] = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else if (ft_strnstr(str, ">", 1))
		fd[1] = open(name, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
	else if (ft_strcmp(str, "<"))
	{
		fd[0] = open(name, O_RDONLY);
		if (fd[0] == -1)
		{
			ft_putstr(name);
			ft_putstr(" :invalide file name");
		}
	}
	else if (ft_strnstr(str, "|", 1))
	{
		pipe(fd);
	}
	dup2(fd[1], 1);
	dup2(fd[0], 0);
	//trouver un moyenne d utiliser fd[0] pour |
	return (i);
}
