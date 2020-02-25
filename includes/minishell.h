/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:43:02 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/24 15:48:50 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_include.h"

void	echo_command(char *line);
void	help();
t_bool	take_env_variable(char *p_src, char *p_target);
t_bool	take_command(char *p_src, char *p_target);
t_elem	**check_command(t_elem **tab, char *buffer);

#endif
