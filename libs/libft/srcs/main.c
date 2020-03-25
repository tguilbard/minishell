/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:47:24 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/26 19:55:40 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

__attribute__ ((destructor)) void ft_quit(void)
{
	system("leaks a.out");
}

int		main(void)
{
	char 	*str;
	char	*str2;
	char 	**str_tab;
	int		int_tab[7] = {7,27,06,28,24,42,29};
	str = ft_strdup("zSzawwwwwzlzut zlzezs gars, c'est un testzwwwwwwwwww");
	str2 = ft_strdup("test");
	printf("\n%s\n", str);
	str = ft_rm_charset(str, "wz");
	printf("%s\n", str);

	printf("\n%d\n", ft_file_exist("tmp.h"));

	str_tab = (char**)malloc(sizeof(char*) * (2 + 1));
	if (str_tab == NULL)
		return (0);
	str_tab[2] = NULL;
	str_tab[0] = str;
	str_tab[1] = str2;
	ft_print_str_tab("Deux chaines de test", str_tab);
	ft_print_int_tab(NULL, int_tab, 7);

	free(str_tab);
	t_char_list c_tab;

	c_tab = create_char_list(2);
	ft_char_list_push_back(&c_tab, str);
	ft_char_list_push_back(&c_tab, str2);
	int i;
	i = 0;
	while (c_tab.data[i])
	{
		printf("%s\n", c_tab.data[i]);
		i++;
	}
	destroy_t_char_list(c_tab);
	return (0);
}
