/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:43:02 by tguilbar          #+#    #+#             */
/*   Updated: 2020/09/15 16:58:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_include.h"

int		mini_pwd(void);
int		mini_echo(char **p_param);
int		mini_exit(char **p_param);
int		mini_env(char **p_param);
int		mini_export(char **p_str);
int		mini_unset(char **p_str);
int		mini_cd(char **path);
int		mini_exec(char **p_param);
int		find_cmd(char **p_param);
char	*get_pwd(void);
void	help(void);
void	set_environ(char **env);
t_param	*replace_environ(t_param *res);
int		find_env_var(char *find);
t_param	*get_param(char *param);
void	ft_get_redirection(char *param, size_t *i, t_param *result, int n);
void	redirection(t_param *param, int n);
void	child_killer(int sig);
void	print_prompt(void);
void	main_execution(void);
void	forker(void);

#endif
