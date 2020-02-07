/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:28:13 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/07 11:53:26 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_command(char *line)
{
	size_t i;
	t_bool find;

	i = 0;
	find = false;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == ' ')
			write(1, " ", 1);
		while (line[i] == ' ')
			i++;
		if (line[i] == '"')
		{
			i++;
			while (line[i] != '"')
			{
				write(1, line + i, 1);
				i++;
			}
		}
		else if (line[i] == 39)
		{
			i++;
			while (line[i] != 39)
			{
				write(1, line + i, 1);
				i++;
			}
		}
		else if (test_command("-n", line + i) && find == false)
		{
			i += 2;
			find = true;
		}
		else
			write(1, line + i, 1);
		i++;
	}
	if (find == false)
		write(1, "\n", 1);
}
