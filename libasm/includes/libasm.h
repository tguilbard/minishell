/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 08:05:55 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/17 13:35:17 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
unsigned long	ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strdup(char *str);
size_t			ft_read(int	fildes, void *buf, size_t nbyte);
size_t			ft_write(int fildes, void *buf, size_t nbyte);

#endif
