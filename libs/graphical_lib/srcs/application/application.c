#include "lgl.h"

t_application create_application(t_vector2 p_size, char *p_prog_name)
{
	t_application result;

	result.mlx_ptr = mlx_init();
	if (result.mlx_ptr == NULL)
		error_exit(5);

	result.prog_name = p_prog_name;

	result.size = p_size;
	result.win_ptr = mlx_new_window(result.mlx_ptr,
			(int)(result.size.x), (int)(result.size.y),
			result.prog_name);
	if (result.win_ptr == NULL)
		error_exit(6);

	result.img_ptr = mlx_new_image(result.mlx_ptr,
			(int)(result.size.x), (int)(result.size.y));
	if (result.img_ptr == NULL)
		error_exit(7);

	result.pixels = mlx_get_data_addr(result.img_ptr, &(result.bits_per_pixel),
						&(result.size_line), &(result.endian));

	return (result);
}

t_application *malloc_application(t_vector2 p_size, char *p_prog_name)
{
	t_application *result;

	result = (t_application *)malloc(sizeof(t_application));
	if (result == NULL)
		error_exit(4);

	*result = create_application(p_size, p_prog_name);

	return (result);
}

void destroy_application(t_application application)
{
	mlx_destroy_window(application.mlx_ptr, application.win_ptr);
}

void free_application(t_application *application)
{
	destroy_application(*application);
	free(application);
}

void put_pixel(t_application *application, t_vector2 pos, t_color color)
{
	int index;

	index = convert_2di_1di(pos, application->size) * 4;
	application->pixels[index + RED_COMP] = color.r;
	application->pixels[index + GREEN_COMP] = color.g;
	application->pixels[index + BLUE_COMP] = color.b;
	application->pixels[index + ALPHA_COMP] = 255 - color.a;
}

void clear_screen(t_application *application)
{
	size_t i;
	size_t j;

	mlx_clear_window(application->mlx_ptr, application->win_ptr);
	i = 0;
	while (i < application->size.x)
	{
		j = 0;
		while (j < application->size.y)
		{
			put_pixel(application, create_vector2(i, j), create_color(40, 40, 40, 255));
			j++;
		}
		i++;
	}
}

void render_screen(t_application *application)
{
	mlx_put_image_to_window(application->mlx_ptr, application->win_ptr,
						application->img_ptr, 0, 0);
}

void application_add_key_control(t_application *application,
		int event, int (*funct)(int , void *), void *param)
{
	mlx_hook(application->win_ptr, event, 0L, funct, param);
}

void application_add_mouse_control(t_application *application,
		int event, int (*funct)(int , void *), void *param)
{
	mlx_hook(application->win_ptr, event, 0L, funct, param);
}

void application_add_exit_control(t_application *application,
		int event, int (*funct)(void))
{
	mlx_hook(application->win_ptr, event, 0L, funct, (void*)0);
}
void application_update(t_application *application, int (*funct)(void *), void *param)
{
	mlx_loop_hook(application->mlx_ptr, funct, param);
}

void run_application(t_application *application)
{
	mlx_loop(application->mlx_ptr);
}
