#include "lgl.h"

t_vector2 create_vector2(float p_x, float p_y)
{
	t_vector2 result;

	result.x = p_x;
	result.y = p_y;

	return (result);
}

t_vector2 *malloc_vector2(float p_x, float p_y)
{
	t_vector2 *result;

	result = (t_vector2 *)malloc(sizeof(t_vector2));
	if (result == NULL)
		error_exit(1);

	*result = create_vector2(p_x, p_y);

	return (result);
}

void destroy_vector2(t_vector2 vector)
{
	(void)vector;
}

void free_vector2(t_vector2 *vector)
{
	destroy_vector2(*vector);
	free(vector);
}

void print_vector2(char *name, t_vector2 vector)
{
	char *tmp;

	lgl_putstr(name);
	lgl_putstr(" : ");

	tmp = vector2_str(vector);
	lgl_putstr(tmp);
	free(tmp);

	lgl_putchar('\n');
}

char *vector2_str(t_vector2 vector)
{
	char *result;
	char *tmp;

	result = lgl_strdup("(");
	tmp = ftoa(vector.x, 3);
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, " / ");
	tmp = ftoa(vector.y, 3);
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, ")");
	return (result);
}

float vector2_distance(t_vector2 p_a, t_vector2 p_b)
{
	float tmp;
	float tmp2;

	tmp = pow(p_b.x - p_a.x, 2);
	tmp2 = pow(p_b.y - p_a.y, 2);
	return (sqrt(tmp + tmp2));
}
