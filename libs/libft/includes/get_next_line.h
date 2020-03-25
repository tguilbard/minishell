/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:37:29 by tguilbar          #+#    #+#             */
/*   Updated: 2020/03/05 23:04:33 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef	struct			s_list_gnl
{
	int					ret;
	int					fd;
	char				*stock;
	struct s_list_gnl	*next;
}						t_list_gnl;

int						get_next_line(int fd, char **line);
unsigned int			strlen2(char *s1, char *s2, int type);
int						check_create(int fd, t_list_gnl **lst);
t_list_gnl				*fb(int fd, t_list_gnl **lst);
void					rm_lst(int fd, t_list_gnl **lst);

#endif
