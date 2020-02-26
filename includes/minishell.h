/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:43:02 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/26 21:15:15 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_include.h"


void	mini_pwd(void);
void	mini_echo(char *p_str);
void	mini_exit(void);
void	mini_env(void);
void	help(void);
void	mini_echo(char *p_str);
void	set_environ(char **env);

#endif
