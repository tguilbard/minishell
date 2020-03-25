/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:49:15 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/26 00:26:39 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** 1 = act in
** 2 = act out
** 3 = next in
** 4 = next out
*/

void		redirection(t_param *param, int n)
{
	static int	*std = NULL;
	static int	in = -1;
	static int 	out = -1;
	size_t			i;
	int			fd[2];

	if (in == -1)
		in = dup(0);
	if (out == -1)
		out = dup(1);
	if (std == NULL)
	{
		std = malloc(sizeof(int) * 4);
		std[2] = in;
		std[3] = out;
	}
	std[0] = std[2];
	std[1] = std[3];
	std[2] = in;
	std[3] = out;
	i = 0;
	if (param->sep[n])
	{
		//ft_putstr("ici\n", 2);
	 	while (param->sep[n][i])	//lieu du crash
		{
			if (*(param->sep[n][i]) == '|')
			{
				pipe(fd);
				std[1] = fd[1];
				std[2] = fd[0];
			}
			else if (*(param->sep[n][i]) == '>')
			{
				if (param->sep[n][i][1] == '>')
					std[1] = open(param->name[n][i], O_WRONLY | O_CREAT | O_APPEND, 0777);
				else
					std[1] = open(param->name[n][i], O_WRONLY | O_CREAT | O_APPEND | O_TRUNC, 0777);
			}
			else if (*(param->sep[n][i]) == '<')
				std[0] = open(param->name[n][i], O_RDONLY, 044);
			i++;
		}
	}
	dup2(std[0], 0);
	close(std[0]);
	dup2(std[1], 1);
	close(std[1]);
}
