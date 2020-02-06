/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:06:39 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/01/31 02:20:12 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "libft_includes.h"
# include "libft_structures.h"
# include "libft_defines.h"
# include "get_next_line.h"

/*
** Prototypage des STRINGS.
*/

char		*ft_strnew(size_t p_len);
char		*ft_strdup(char *p_src);
char		*ft_strdup_c(char p_c);
size_t		ft_strlen(char	*p_src);
size_t		ft_strlen_arg(char *p_str, char p_c);
t_bool		ft_strcmp(char *p_src, char *p_target);
t_bool		ft_strcmp_c(char *p_src, char p_target);
char		*ft_strcpy(char *p_src, char *p_dest);
char		*ft_strsub(char *p_src, size_t p_start, size_t p_len);
char		*ft_strjoin(char *p_str1, char *p_str2);
char		*ft_strstr(char *p_haystack, char *p_needle);
char		**ft_split(char *p_src, char p_sep);
void		ft_str_add_prefixe(char *p_prefixe, char **p_str);
void		ft_str_add_suffix(char **p_str, char *p_suffix);

/*
** Prototypage des CONVERTS.
*/

float		ft_f_roof(float p_value);
int			ft_i_roof(float p_value);
float		ft_f_floor(float p_value);
float		ft_f_round(float p_value);
int			ft_i_abs(int p_value);
float		ft_f_abs(float p_value);
char		*ft_itoa_base(long long int nbr, char *base);
char		*ft_itoa(long long int nbr);
char		*ft_itoa_hexa(long long int nbr);
char		*ft_itoa_octa(long long int nbr);
char		*ft_itoa_unsigned_deci(unsigned int nbr);
int			ft_atoi(char *p_str);
/*
** Prototypage des LISTS.
*/

t_list		*ft_lst_create_node(void *p_data);
void		ft_lst_add_back(t_list **p_list, t_list *p_node);
void		ft_lst_add_front(t_list **p_list, t_list *p_node);

/*
** Prototypage des IO.
*/

void		ft_putchar(char c);
void		ft_putstr(char *str);

size_t		ft_tab_len(char **tab);
void		ft_tab_free(char **tab);

#endif
