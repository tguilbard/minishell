/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:28:13 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/21 13:14:16 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_command(char *line)
{
	size_t	i;
	int		find;

	i = 0;
	find = 0;
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			write(1, " ", 1);
			while (line[i] == ' ' && line[i])
				i++;
		}
		else if (line[i] == '"')
		{
			i++;
			while (line[i] != '"' && line[i])
			{
				write(1, line + i, 1);
				i++;
			}
		}
		else if (line[i] == 39)
		{
			i++;
			while (line[i] != 39 && line[i])
			{
				write(1, line + i, 1);
				i++;
			}
		}
		if (take_command("-n", line + i) && find == 0)
		{
			i += 2;
			find = 1;
			while(line[i] == ' ' && line[i])
				i++;
		}
		else
			while (line[i] != ' ' && line[i])
			{
				write(1, line + i, 1);
				i++;
			}
		find = (find == 1)? 1 : -1;
	}
	if (find != 1)
		write(1, "\n", 1);
}
