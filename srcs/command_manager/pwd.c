/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:56:31 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/27 11:58:40 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_pwd(void)
{
	char *pwd;

	pwd = get_pwd();
	ft_str_add_suffix(&pwd, "\n");
	ft_putstr(pwd);
	free(pwd);
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
