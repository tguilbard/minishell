/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:49:15 by tguilbar          #+#    #+#             */
/*   Updated: 2020/09/14 16:18:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** 0 = act in
** 1 = act out
** 2 = next in
** 3 = next out
*/

static int	redirection_forest(t_param *param, int n, size_t i, int *std)
{
	int fd[2];

	if (*(param->sep[n][i]) == '|')
	{
		pipe(fd);
		std[1] = fd[1];
		std[2] = fd[0];
		return (1);
	}
	else if (*(param->sep[n][i]) == '>')
	{
		if (param->sep[n][i][1] == '>')
			std[1] = open(param->name[n][i], O_WRONLY | O_CREAT |
													O_APPEND, 0777);
		else
			std[1] = open(param->name[n][i], O_WRONLY | O_CREAT |
											O_APPEND | O_TRUNC, 0777);
	}
	else if (*(param->sep[n][i]) == '<')
		std[0] = open(param->name[n][i], O_RDONLY, 044);
	return (0);
}

static int	*redirection_init(void)
{
	static int	*std = NULL;
	static int	in = -1;
	static int	out = -1;

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
	return (std);
}

void		redirection(t_param *param, int n)
{
	int		*std;
	size_t	i;
	int		ret;

	std = redirection_init();
	i = 0;
	ret = 0;
	if (param->sep[n])
	{
		while (param->sep[n][i])
		{
			ret = redirection_forest(param, n, i, std);
			i++;
		}
	}
	dup2(std[0], 0);
	dup2(std[1], 1);
	if (ret == 1)
	{
		close(std[0]);
		close(std[1]);
	}
}
