#include "lgl.h"

t_vector4 create_vector4(float p_x, float p_y, float p_z, float p_w)
{
	t_vector4 result;

	result.x = p_x;
	result.y = p_y;
	result.z = p_z;
	result.w = p_w;

	return (result);
}

t_vector4 *malloc_vector4(float p_x, float p_y, float p_z, float p_w)
{
	t_vector4 *result;

	result = (t_vector4 *)malloc(sizeof(t_vector4));
	if (result == NULL)
		error_exit(3);

	*result = create_vector4(p_x, p_y, p_z, p_w);

	return (result);
}

void destroy_vector4(t_vector4 vector)
{
	(void)vector;
}

void free_vector4(t_vector4 *vector)
{
	destroy_vector4(*vector);
	free(vector);
}

void print_vector4(char *name, t_vector4 vector)
{
	char *tmp;

	lgl_putstr(name);
	lgl_putstr(" : ");

	tmp = vector4_str(vector);
	lgl_putstr(tmp);
	free(tmp);

	lgl_putchar('\n');
}

char *vector4_str(t_vector4 vector)
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
	lgl_stradd_back(&result, " / ");
	tmp = ftoa(vector.z, 3);
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, " / ");
	tmp = ftoa(vector.w, 3);
	lgl_stradd_back(&result, tmp);
	free(tmp);
	lgl_stradd_back(&result, ")");
	return (result);
}
