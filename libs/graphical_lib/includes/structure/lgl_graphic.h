#ifndef LGL_GRAPHIC_H
#define LGL_GRAPHIC_H

typedef struct 	s_color
{
	int 		r;
	int 		g;
	int 		b;
	int 		a;
}				t_color;

t_color 		create_color(int p_r, int p_g, int p_b, int p_a);
t_color 		*malloc_color(int p_r, int p_g, int p_b, int p_a);

void 			destroy_color(t_color color);
void 			free_color(t_color *color);

int 			color_int(t_color color);

void 			print_color(char *name, t_color color);
char 			*color_str(t_color color);

#endif
