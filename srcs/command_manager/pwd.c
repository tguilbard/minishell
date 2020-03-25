/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:56:31 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/25 00:59:02 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_pwd(void)
{
	char *pwd;

	pwd = get_pwd();
	ft_str_add_suffix(&pwd, "\n");
	ft_putstr(pwd, 1);
	free(pwd);
	return (0);
}

char	*get_pwd(void)
{
	char	*buf;
	char	*mem;
	size_t	size;

	buf = NULL;
	mem = NULL;
	size = 16;
	while (buf == NULL)
	{
		free(mem);
		buf = malloc(sizeof(char) * (size));
		if (buf == NULL)
			return (NULL);
		mem = buf;
		buf = getcwd(buf, size);
		size += 16;
	}
	return (buf);
}
