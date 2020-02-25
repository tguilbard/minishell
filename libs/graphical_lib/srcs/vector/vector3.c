#include "lgl.h"

t_vector3 create_vector3(float p_x, float p_y, float p_z)
{
	t_vector3 result;

	result.x = p_x;
	result.y = p_y;
	result.z = p_z;

	return (result);
}

t_vector3 *malloc_vector3(float p_x, float p_y, float p_z)
{
	t_vector3 *result;

	result = (t_vector3 *)malloc(sizeof(t_vector3));
	if (result == NULL)
		error_exit(2);

	*result = create_vector3(p_x, p_y, p_z);

	return (result);
}

void destroy_vector3(t_vector3 vector)
{
	(void)vector;
}

void free_vector3(t_vector3 *vector)
{
	destroy_vector3(*vector);
	free(vector);
}

void print_vector3(char *name, t_vector3 vector)
{
	char *tmp;

	lgl_putstr(name);
	lgl_putstr(" : ");

	tmp = vector3_str(vector);
	lgl_putstr(tmp);
	free(tmp);

	lgl_putchar('\n');
}

char *vector3_str(t_vector3 vector)
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
	lgl_stradd_back(&result, ")");
	return (result);
}
