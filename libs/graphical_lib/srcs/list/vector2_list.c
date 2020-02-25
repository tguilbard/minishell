#include "lgl.h"

t_vector2 **lgl_t_vector2tab_new(size_t nb)
{
	t_vector2 **tab;
	size_t i;

	tab = (t_vector2 **)malloc(sizeof(t_vector2 *) * (nb + 1));
	i = 0;
	while (i <= nb)
	{
		tab[i] = NULL;
		i++;
	}

	return (tab);
}

t_vector2 *lgl_t_vector2array_new(size_t nb)
{
	t_vector2 *array;

	array = (t_vector2 *)malloc(sizeof(t_vector2) * nb);

	return (array);
}

void lgl_t_vector2tab_cpy(t_vector2 **old, t_vector2 **new)
{
	size_t i;

	i = 0;
	while (old[i] != NULL)
	{
		new[i] = old[i];
		i++;
	}
}

size_t t_vector2_list_calc_line(t_vector2_list *list, size_t index)
{
	size_t result;

	result = index / list->push_size;

	return (result);
}

size_t t_vector2_list_calc_elem(t_vector2_list *list, size_t index)
{
	size_t result;
	size_t nb_line;

	nb_line = t_vector2_list_calc_line(list, index);
	result = index - (nb_line * list->push_size);

	return (result);
}

t_vector2_list create_t_vector2_list(size_t p_push_size)
{
	t_vector2_list result;

	result.size = 0;
	result.push_size = p_push_size;
	result.max_size = result.push_size;
	result.data = lgl_t_vector2tab_new(1);
	result.data[0] = lgl_t_vector2array_new(result.push_size);

	return (result);
}

t_vector2_list *malloc_t_vector2_list(size_t p_push_size)
{
	t_vector2_list *t_vector2_result;

	t_vector2_result = (t_vector2_list *)malloc(sizeof(t_vector2_list));

	*t_vector2_result = create_t_vector2_list(p_push_size);

	return (t_vector2_result);
}

void destroy_t_vector2_list(t_vector2_list to_delete)
{
	size_t i;
	size_t nb_line;

	nb_line = to_delete.max_size / to_delete.push_size;
	i = 0;
	while (i < nb_line)
	{
		free(to_delete.data[i]);
		i++;
	}
	free(to_delete.data);
}

void free_t_vector2_list(t_vector2_list *to_free)
{
	destroy_t_vector2_list(*to_free);
	free(to_free);
}

void t_vector2_list_push_back(t_vector2_list *list, t_vector2 to_add)
{
	size_t nb_line;
	size_t nb_elem;

	if (list->size + 1 >= list->max_size)
	{
		t_vector2 **tmp;
		size_t nb_line;

		tmp = list->data;
		nb_line = list->max_size / list->push_size;
		list->data = lgl_t_vector2tab_new(nb_line + 1);
		lgl_t_vector2tab_cpy(tmp, list->data);
		list->data[nb_line] = lgl_t_vector2array_new(list->push_size);
		list->max_size += list->push_size;
	}

	nb_line = t_vector2_list_calc_line(list, list->size);
	nb_elem = t_vector2_list_calc_elem(list, list->size);

	list->data[nb_line][nb_elem] = to_add;
	list->size++;
}

t_vector2 t_vector2_list_at(t_vector2_list *list, size_t index)
{
	size_t nb_line;
	size_t nb_elem;

	if (list->size == 0)
		return (create_vector2(0, 0));

	nb_line = t_vector2_list_calc_line(list, index);
	nb_elem = t_vector2_list_calc_elem(list, index);

	if (list->size > index)
		return (list->data[nb_line][nb_elem]);

	nb_line = t_vector2_list_calc_line(list, list->size);
	nb_elem = t_vector2_list_calc_elem(list, list->size);

	return (list->data[nb_line][nb_elem]);
}

void t_vector2_list_clear(t_vector2_list *list)
{
	list->size = 0;
}

void print_t_vector2_list(t_vector2_list *list)
{
	size_t nb_line;
	size_t nb_elem;
	size_t index;

	index = 0;
	printf("List : ");
	while (index < list->size)
	{
		if (index != 0)
			printf(" - ");

		nb_line = t_vector2_list_calc_line(list, index);
		nb_elem = t_vector2_list_calc_elem(list, index);

		if ((int)list->data[nb_line][nb_elem].x == 0)
			printf("[%s]", vector2_str(list->data[nb_line][nb_elem]));
		else
			printf("[%s]", vector2_str(list->data[nb_line][nb_elem]));

		index++;
	}
	printf("\n");
}
