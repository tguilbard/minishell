#ifndef LGL_APPLICATION_H
#define LGL_APPLICATION_H

typedef struct	s_application
{
	void		*mlx_ptr;
	void		*win_ptr;

	void		*img_ptr;
	char		*pixels;
	int 		bits_per_pixel;
	int 		size_line;
	int 		endian;

	char		*prog_name;
	t_vector2	size;
}				t_application;

t_application 	create_application(t_vector2 p_size, char *p_prog_name);
t_application 	*malloc_application(t_vector2 p_size, char *p_prog_name);

void 			destroy_application(t_application application);
void 			free_application(t_application *application);

void 			clear_screen(t_application *application);
void 			put_pixel(t_application *application,
												t_vector2 pos, t_color color);
void 			render_screen(t_application *application);
void 			application_add_key_control(t_application *application,
					int event, int (*funct)(int , void *), void *param);
void 			application_add_mouse_control(t_application *application,
					int event, int (*funct)(int , void *), void *param);
void			application_add_exit_control(t_application *application,
					int event, int (*funct)(void));
void 			application_update(t_application *application,
					int (*funct)(void *), void *param);
void 			run_application(t_application *application);

#endif
