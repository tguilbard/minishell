/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:35:24 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 13:37:00 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LGL_MATH_H
# define LGL_MATH_H

typedef struct	s_vector2
{
	float		x;
	float		y;
}				t_vector2;

t_vector2		create_vector2(float p_x, float p_y);
t_vector2		*malloc_vector2(float p_x, float p_y);
void			destroy_vector2(t_vector2 vector);
void			free_vector2(t_vector2 *vector);
void			print_vector2(char *name, t_vector2 vector);
char			*vector2_str(t_vector2 vector);
float			vector2_distance(t_vector2 p_a, t_vector2 p_b);
t_vector2		normalize_vector2(t_vector2 p_vector);

typedef struct	s_vector3
{
	float		x;
	float		y;
	float		z;
}				t_vector3;

t_vector3		create_vector3(float p_x, float p_y, float p_z);
t_vector3		*malloc_vector3(float p_x, float p_y, float p_z);
void			destroy_vector3(t_vector3 vector);
void			free_vector3(t_vector3 *vector);
void			print_vector3(char *name, t_vector3 vector);
char			*vector3_str(t_vector3 vector);

typedef struct	s_vector4
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vector4;

t_vector4		create_vector4(float p_x, float p_y, float p_z, float p_w);
t_vector4		*malloc_vector4(float p_x, float p_y, float p_z, float p_w);
void			destroy_vector4(t_vector4 vector);
void			free_vector4(t_vector4 *vector);
void			print_vector4(char *name, t_vector4 vector);
char			*vector4_str(t_vector4 vector);

int				lgl_pow(int x, unsigned int y);
int				convert_2di_1di(t_vector2 pos, t_vector2 size);
float			convert_2d_1d(t_vector2 pos, t_vector2 size);

#endif
