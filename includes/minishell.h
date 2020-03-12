/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:43:02 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/12 12:52:14 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_include.h"

int		mini_pwd(void);
char	*get_pwd(void);
int		mini_echo(char **p_param);
int		mini_exec(char **p_param);
int		mini_exit(void);
int		mini_env(void);
int		mini_export(char **p_str);
int		mini_unset(char **p_str);
int		mini_cd(char **path);
void	help(void);
void	set_environ(char **env);
int		find_env_var(char *find);
char	***get_param(char *param);
int		redirection(char *str);

#endif
