/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:43:02 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/04 07:35:15 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_include.h"


void	mini_pwd(void);
char	*get_pwd(void);
void	mini_echo(char *p_str);
void	mini_exit(void);
void	mini_env(void);
void	mini_export(char *p_str);
void	mini_unset(char *p_str);
void	mini_cd(char *path);
void	help(void);
void	mini_echo(char *p_str);
void	set_environ(char **env);
int		find_env_var(char *find);
char	**get_param(char *param);

#endif
