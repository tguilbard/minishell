/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:44:00 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 01:40:43 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

t_langage g_langage;

char *g_error_msg[][3] = {
	{
		"Error",
		"Erreur",
		"Error"
	},
	{
		"Can't malloc a vector2",
		"Echec du malloc d'un vector2",
		"No puedo malloc un vector2"
	},
	{
		"Can't malloc a vector3",
		"Echec du malloc d'un vector3",
		"No puedo malloc un vector3"
	},
	{
		"Can't malloc a vector4",
		"Echec du malloc d'un vector4",
		"No puedo malloc un vector4"
	},
	{
		"Can't malloc an application",
		"Echec du malloc d'une application",
		"No puedo malloc una aplicacion"
	},
	{
		"Can't initialize mlx_ptr",
		"Echec de l'initialisation du mlx_ptr",
		"No se puede inicializar mlx_ptr"
	},
	{
		"Can't initialize win_ptr",
		"Echec de l'initialisation du win_ptr",
		"No se puede inicializar win_ptr"
	},
	{
		"Can't initialize img_ptr",
		"Echec de l'initialisation du img_ptr",
		"No se puede inicializar img_ptr"
	},
	{
		"Libft error",
		"Libft error",
		"Libft error"
	},
	{
		"Libft error 2",
		"Libft error 2",
		"Libft error 2"
	},
	{
		"Can't malloc a color",
		"Echec du malloc d'un couleur",
		"No puedo malloc una color"
	},
	{
		"Program close successfully",
		"Le programme s'est arrete correctement",
		"Programa cerrado exitosamente"
	},
	{
		"Can't malloc a panel",
		"Echec du malloc d'un panneau",
		"No puedo malloc un panel"
	},
	{
		"Can't malloc a button",
		"Echec du malloc d'un bouton",
		"No puedo malloc un boton"
	},
	{
		"Can't malloc an image",
		"Echec du malloc d'une image",
		"No puedo malloc una imagen"
	}
};

void		set_langage(t_langage p_langage)
{
	g_langage = p_langage;
}

static void	good_exit(void)
{
	lgl_putstr(g_error_msg[11][(int)g_langage]);
	lgl_putchar('\n');
	exit(0);
}

void		error_exit(int error)
{
	if (error == 11)
		good_exit();
	lgl_putstr(g_error_msg[0][(int)g_langage]);
	lgl_putstr(" [");
	lgl_putnbr(error);
	lgl_putstr("] : ");
	lgl_putstr(g_error_msg[error][(int)g_langage]);
	lgl_putchar('\n');
	exit(error);
}
