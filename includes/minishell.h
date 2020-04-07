/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:43:02 by tguilbar          #+#    #+#             */
/*   Updated: 2020/04/07 19:06:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_include.h"

int		mini_pwd(void);
char	*get_pwd(void);
int		mini_echo(char **p_param);
int		mini_exec(char **p_param);
int		mini_exit(char **p_param);
int		mini_env(void);
int		mini_export(char **p_str);
int		mini_unset(char **p_str);
int		mini_cd(char **path);
void	help(void);
void	set_environ(char **env);
int		find_env_var(char *find);
t_param	*get_param(char *param);
void	redirection(t_param *param, int n);
void	child_killer(int sig);

#endif
