/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:48:41 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/21 14:34:03 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

#define CYAN printf("%s", "\x1B[36m");
#define RED printf("%s", "\x1B[31m");
#define GREEN printf("%s", "\x1B[32m");
#define PURPLE printf("%s", "\x1B[35m");
#define NORMAL printf("%s", "\x1B[0m");
#define WHITE printf("%s", "\x1B[37m");

void	ascii_art(void)
{
	GREEN
	printf("\n                        1111111111111111111111111111111111111111\n \
			11111111111"); CYAN printf("00000"); GREEN printf("111111111111111111111111\n \
			1111111111"); CYAN printf("0000000"); GREEN printf("11111111111111111111111\n \
			111111111"); CYAN printf("000"); GREEN printf("111"); CYAN printf("00"); GREEN printf("11111111111111111111111\n \
			111111111"); CYAN printf("00"); GREEN printf("1111"); CYAN printf("00"); GREEN printf("11111111111111111111111\n \
			11111111"); CYAN printf("000"); GREEN printf("1111"); CYAN printf("000"); GREEN printf("1111111111111111111111\n \
			11111111"); CYAN printf("000"); GREEN printf("1111"); CYAN printf("000"); GREEN printf("1111111111111111111111\n \
			111111111"); CYAN printf("00"); GREEN printf("11111"); CYAN printf("000"); GREEN printf("111111111111111111111\n \
			111111111"); CYAN printf("000"); GREEN printf("11111"); CYAN printf("000"); GREEN printf("11111111111111111111\n \
			1111111111"); CYAN printf("000"); GREEN printf("11111"); CYAN printf("0000"); GREEN printf("111111111111111111\n \
			11111111111"); CYAN printf("00"); GREEN printf("111111"); CYAN printf("0000"); GREEN printf("11111111111111111\n \
			11111111111"); CYAN printf("000"); GREEN printf("1111111"); CYAN printf("000"); GREEN printf("1111111111111111\n \
			111111111111"); CYAN printf("000"); GREEN printf("1111111"); CYAN printf("000"); GREEN printf("111111111111111\n \
			111111111111"); CYAN printf("000"); GREEN printf("11111111"); CYAN printf("000"); GREEN printf("11111111111111\n \
			1111111111111"); CYAN printf("00"); GREEN printf("1111111111"); CYAN printf("000"); GREEN printf("111111111111\n \
			111111111"); CYAN printf("000"); GREEN printf("1"); CYAN printf("000"); GREEN printf("1111111111"); CYAN printf("00"); GREEN printf("111111111111\n \
			1111"); CYAN printf("000000000000"); GREEN printf("11111111111"); CYAN printf("000"); GREEN printf("1111111111\n \
			11"); CYAN printf("00000000"); GREEN printf("111111111111111111"); CYAN printf("000"); GREEN printf("111111111\n \
			1"); CYAN printf("000"); GREEN printf("1111111111111111111111111"); CYAN printf("000000000"); GREEN printf("11\n \
			"); CYAN printf("000"); GREEN printf("1111"); CYAN printf("000000000"); GREEN printf("111111111111111111"); CYAN printf("00000"); GREEN printf("1\n \
			"); CYAN printf("00"); GREEN printf("111"); CYAN printf("0000000"); GREEN printf("1"); CYAN printf("0000"); GREEN printf("1111111111111111111"); CYAN printf("000"); GREEN printf("1\n \
			"); CYAN printf("00"); GREEN printf("1111"); CYAN printf("000"); GREEN printf("1111111"); CYAN printf("000"); GREEN printf("111111111111111111"); CYAN printf("00"); GREEN printf("1\n \
			"); CYAN printf("000"); GREEN printf("11111111111"); CYAN printf("00000"); GREEN printf("111111111111111111"); CYAN printf("00"); GREEN printf("1\n \
			1"); CYAN printf("000"); GREEN printf("1111111"); CYAN printf("00000000"); GREEN printf("111111111111111111"); CYAN printf("00"); GREEN printf("1\n \
			11"); CYAN printf("000000000000"); GREEN printf("111"); CYAN printf("0000"); GREEN printf("1111111111111111"); CYAN printf("00"); GREEN printf("1\n \
			1"); CYAN printf("000"); GREEN printf("1"); CYAN printf("000000"); GREEN printf("1111111"); CYAN printf("0000"); GREEN printf("111111111111111"); CYAN printf("00"); GREEN printf("1\n \
			1"); CYAN printf("000"); GREEN printf("11111111111"); CYAN printf("000000"); GREEN printf("1111111111111111"); CYAN printf("00"); GREEN printf("1\n \
			11"); CYAN printf("0000"); GREEN printf("1"); CYAN printf("0000"); GREEN printf("1"); CYAN printf("0000000000"); GREEN printf("111111111111111"); CYAN printf("00"); GREEN printf("1\n \
			111"); CYAN printf("000000000000"); GREEN printf("11111"); CYAN printf("000"); GREEN printf("1111111111111"); CYAN printf("000"); GREEN printf("1\n \
			1111"); CYAN printf("00"); GREEN printf("11111111111"); CYAN printf("0000000"); GREEN printf("1111111"); CYAN printf("0000000"); GREEN printf("11\n \
			1111"); CYAN printf("0000"); GREEN printf("111111"); CYAN printf("00000000"); GREEN printf("11111111"); CYAN printf("00000000"); GREEN printf("11\n \
			11111"); CYAN printf("000000000000"); GREEN printf("111"); CYAN printf("000"); GREEN printf("11111"); CYAN printf("000"); GREEN printf("111111111\n \
			11111111"); CYAN printf("000"); GREEN printf("1"); CYAN printf("0"); GREEN printf("1"); CYAN printf("0"); GREEN printf("111111"); CYAN printf("000"); GREEN printf("111"); CYAN printf("000"); GREEN printf("1111111111\n \
			11111111"); CYAN printf("000"); GREEN printf("111111"); CYAN printf("00000"); GREEN printf("11"); CYAN printf("00000"); GREEN printf("11111111111\n \
			111111111"); CYAN printf("000000000000000000"); GREEN printf("1111111111111\n \
			1111111111"); CYAN printf("00000000000000"); GREEN printf("1111111111111111\n \
			1111111111111111111111111111111111111111\n");
}

__attribute__ ((destructor))int end(void)
{
	NORMAL
	return (0);
}

int		main(void)
{
	char	str3[0] = {};
	char *str1;
	str1 = strdup("test");
	char *str2;
	str2 = strdup("another test");
	char *tmp = NULL;
	char *tmp2 = "string";
	char ret_char;

	start: WHITE
	printf("\n         Choose the test you wanna do :\n 1:len 2:cmp 3:cpy 4:dup 5:write 6:read 7:exit\n");
	while(1)
	{
		ret_char = getchar();
		if (ret_char == '1')
			goto test_len;
		else if (ret_char == '2')
			goto test_cmp;
		else if (ret_char == '3')
			goto test_cpy;
		else if (ret_char == '4')
			goto test_dup;
		else if (ret_char == '5')
			goto test_write;
		else if (ret_char == '6')
			goto test_read;
		else if (ret_char == '7')
			goto exit_point;
	}
	/*
	**	A bunch of test for str_len
	*/

	test_len:	CYAN

	printf("\nSTR_LEN tests.\n");

	GREEN

	printf("\nString [%s] has {%lu} char\n", "This is a test 18:", ft_strlen("This is a test 18:"));
	printf("String [%s] has {%lu} char\n", "C", ft_strlen("C"));
	printf("String [%s] has {%lu} char\n", "Teeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeest 65:", ft_strlen("Teeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeest 65:"));
	printf("String [%s] has {%lu} char\n", str3, ft_strlen(str3));

	/*
	** Test of wrong inputs.
	*/

	PURPLE

	printf("String [%s] has {%lu} char\n", NULL, ft_strlen(NULL));

	NORMAL
	goto start;

	test_cmp: CYAN

	/*
	**	A bunch of test for str_cmp
	*/

	printf("\nSTR_CMP tests.\n");

	GREEN

	printf("\nComp between [%s] and [%s] = {%d}\n", "Test", "Tes", ft_strcmp("Test", "Tes"));
	printf("Comp between [%s] and [%s] = {%d}\n", "Tes", "Test", ft_strcmp("Tes", "Test"));
	printf("Comp between [%s] and [%s] = {%d}\n", "Test", "Test", ft_strcmp("Test", "Test"));
	printf("Comp between [%s] and [%s] = {%d}\n", str3, "Test", ft_strcmp(str3, "Test"));
	printf("Comp between [%s] and [%s] = {%d}\n", "Test", str3, ft_strcmp("Test", str3));
	printf("Comp between [%s] and [%s] = {%d}\n", str3, str3, ft_strcmp(str3, str3));
	printf("Comp between [%s] and [%s] = {%d}\n", NULL, NULL, ft_strcmp(NULL, NULL));

	/*
	** Test of wrong inputs.
	*/

	PURPLE

	printf("Comp between [%s] and [%s] = {%d}\n", NULL, "TEST", ft_strcmp(NULL, "TEST"));
	printf("Comp between [%s] and [%s] = {%d}\n", "TEST", NULL, ft_strcmp("TEST", NULL));

	NORMAL
	goto start;

	test_cpy: CYAN

	/*
	**	A bunch of test for str_cpy
	*/

	printf("\nSTR_CPY tests.\n");

	GREEN

	printf("\nCopy to str2:[%s] from str1:[%s] = ", str2, str1);
	printf("[%s]\n", ft_strcpy(str2, str1));
	str1[0] = '|';
	printf("Insert caracter in str1:[%s] str2:[%s]\n", str1, str2);
	ft_strcpy(str2, "another test");
	ft_strcpy(str1, "test");
	/*
	** Test of wrong inputs.
	*/
	PURPLE

	printf("Copy to [%s] from [%s] = [%s]\n", "test", NULL, ft_strcpy("test", NULL));
	printf("Copy to [%s] from [%s] = [%s]\n", NULL, "test", ft_strcpy(NULL, "test"));
	//printf("Copy to [%s] from [%s] = ", tmp, "test");
	//printf("[%s]\n", ft_strcpy(tmp, "test"));
	//printf("Copy to [%s] from [%s] = ", str1, str2);
	//printf("[%s]\n", tmp = ft_strcpy(str1, str2));

	NORMAL
	goto start;

	test_dup: CYAN

	/*
	**	A bunch of test for str_dup
	*/

	printf("\nSTR_DUP tests.\n");

	GREEN

	printf("\nDuplication of [%s] in [%s] = ", str1, tmp);
	printf("[%s]\n", tmp = ft_strdup(str1));
	tmp = "another test";
	printf("Duplication of [%s] in [%s] = ", "string", tmp);
	printf("[%s]\n", tmp = ft_strdup("string"));
	tmp = "another test";
	printf("Duplication of [%s] in [%s] = ", tmp, tmp2);
	printf("[%s]\n", tmp2 = ft_strdup(tmp));

	/*
	** Test of wrong inputs.
	*/

	PURPLE

	printf("Duplication of [%s] in [%s] = ", NULL, tmp);
	printf("[%s]\n", tmp = ft_strdup(NULL));
	tmp = NULL;
	printf("Duplication of [%s] in [%s] = ", NULL, tmp);
	printf("[%s]\n", tmp = ft_strdup(NULL));

	NORMAL
	goto start;

	test_write: CYAN

	/*
	**	A bunch of test for write
	*/
	printf("\nWRITE tests.\n");

	GREEN

	printf("%zu\n", ft_write(1, "\nthis is a test ", 16));
	tmp = "test";
	printf(" %zu\n", ft_write(1, tmp, ft_strlen(tmp)));

	/*
	** Test of wrong inputs.
	*/

	PURPLE
	tmp = NULL;

	printf("%zu\n", ft_write(0, tmp, ft_strlen(tmp)));
	printf("%zu\n", ft_write(42, "lol", ft_strlen("lol")));

	NORMAL
	goto start;

	test_read: CYAN

	/*
	**	A bunch of test for read
	*/

	printf("\nREAD tests.\n");

	GREEN

	tmp = (char*)malloc(sizeof(char) * (2000 + 1));
	if (tmp == NULL)
		return (0);
	int fd = open("srcs/ft_strdup.s", O_RDONLY);
	int ret;
	ret = ft_read(fd, tmp, 2000);
	tmp[ret] = '\0';
	printf("\n%s [%d has been read]\n", tmp, ret);
	close(fd);

	fd = open("includes/libasm.h", O_RDONLY);
	ret = ft_read(fd, tmp, 2000);
	tmp[ret] = '\0';
	printf("\n%s [%d has been read]\n", tmp, ret);
	close(fd);

	NORMAL
	printf("\nTest of standard entry\n");
	GREEN
	ret = ft_read(0, tmp, 2000);
	tmp[ret] = '\0';
	printf("\n%s [%d has been read]\n", tmp, ret);
	close(fd);

	/*
	** Test of wrong inputs.
	*/

	PURPLE

	tmp = (char*)malloc(sizeof(char) * (2000 + 1));
	if (tmp == NULL)
		return (0);
	fd = open("It's a trap", O_RDONLY);
	ret = ft_read(fd, tmp, 2000);
	tmp[ret] = '\0';
	printf("\n%s [%d has been read]\n", tmp, ret);
	close(fd);
	ret = ft_read(fd, tmp, 2000);
	tmp[ret] = '\0';
	printf("\n%s [%d has been read]\n", tmp, ret);
	goto start;

	exit_point:

	ascii_art();
	return (0);
}
