/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:07:45 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/07 11:50:34 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(char *prompt)
{
	write(1, prompt, ft_strlen(prompt));
}

int main()
{
	char	*line;
	size_t	i;
	int		ret;

	prompt(USER);
	while ((ret = get_next_line(0, &line)) != -1)
	{
		i = 0;
		while (line[i])
		{
			if (test_command("echo", line + i))
			{
				i += 4;
				echo_command(line + i);
				break;
			}
			else if (test_command("help", line + i))
			{
				help();
				break;
			}
			else if (test_command("exit", line + i))
				exit(0);
			i++;
		}
		free(line);
		if (ret == 0)
			write(1, "\n", 1);
		prompt(USER);
	}
}
