#include "lgl.h"

int test(int key, void *param)
{
	if (key == ESC_KEY)
		error_exit(11);

	return (0);
}

int update(void *param)
{
	t_application 	*app;
	static int		i = 0;

	app = (t_application *)(param);
	clear_screen(app);

	draw_rectangle(app, create_vector2(50.0f, 50.0f), create_vector2(50.0f + i, 150.0f + i), create_color(255, 0, 0, 255));
	draw_circle(app, create_vector2(75.0f + i + i, 75.0f), 25, create_color(0, 255, 125, 255));
	draw_line(app, create_vector2(75.0f, 75.0f), create_vector2(275.0f + (i++), 75.0f), create_color(120, 0, 125, 255), 5);

	render_screen(app);

	return (0);
}

int main()
{
	/*
	** STRINGS test
	*/

	char *str1;
	char *str2;

	str1 	 = lgl_strnew(5);
	str1[0]  = 'C';
	str1[1]  = 'e';
	str1[2]  = 'c';
	str1[3]  = 'i';
	str1[4]  = ' ';

	str2 	 = lgl_strnew(11);
	str2[0]  = 'e';
	str2[1]  = 's';
	str2[2]  = 't';
	str2[3]  = ' ';
	str2[4]  = 'u';
	str2[5]  = 'n';
	str2[6]  = ' ';
	str2[7]  = 't';
	str2[8]  = 'e';
	str2[9]  = 's';
	str2[10] = 't';


	lgl_stradd_back(&str2, str1);
	printf("new string : %s\n", str2);

	/*
	** CALCULS test
	*/

	float angle = 180;
	printf("angle degree : %f\n", angle);
	angle = degree_to_radian(angle);
	printf("angle radian: %f\n", angle);
	angle = radian_to_degree(angle);
	printf("angle degree : %f\n", angle);

	/*
	** GRAPHiCAL test
	*/

	t_application *app;

	app = malloc_application(create_vector2(1200.0f, 800.0f), "char *p_prog_name");

	application_add_key_control(app, KEYPRESS, &test, NULL);
	application_update(app, &update, app);
	run_application(app);
	return (0);
}
