/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:07:45 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/06 16:27:56 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	test_command(char *p_src, char *p_target)
{
	int	i;

	i = 0;
	if (p_src == NULL || p_target == NULL)
		return (0);
	while (p_src[i] != '\0' && p_target[i] != '\0')
	{
		if (p_src[i] != p_target[i])
			return (false);
		i++;
	}
	return (true);
}

void	prompt(char *prompt)
{
	write(1, prompt, ft_strlen(prompt));
}

int main(int ac,char **av)
{
	char	*line;
	size_t	i;
	int		ret;

	if (ac != 1)
		exit(0);
	prompt("user:");
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
		prompt("user:");
	}
}
