/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:52:27 by ldutriez          #+#    #+#             */
/*   Updated: 2020/03/12 13:06:07 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_char_list	g_env;
int					g_env_fd[2];

static char		*get_usr(void)
{
	char	*result;
	int		index;

	index = find_env_var("USER");
	if (index != -1)
	{
		result = ft_strdup(g_env.data[index] + 5);
		return (result);
	}
	return (ft_strdup("unknow"));
}

static void		ft_put_rainbow(char *str)
{
	char	*format;
	size_t	i;
	size_t	len;
	int		j;
	int		color;

	i = 0;
	color = 91;
	len = ft_strlen(str);
	while (str[i])
	{
		format = ft_itoa(color);
		ft_str_add_prefixe("\033[1;", &format);
		ft_str_add_suffix(&format, "m");
		ft_putstr(format);
		j = 0;
		while (j < (int)(len / 7) + 1)
		{
			write(1, str + i + j, 1);
			j++;
			if (!str[i + j])
			 	break ;
		}
		i += j;
		ft_putstr("\033[0m");
		if (color == 97)
			color = 91;
		else
			color++;
	}
}
static void		print_prompt(void)
{
	int		i;
	int		last;
	char	*str[2];

	str[0] = get_pwd();
	i = 0;
	last = 0;
	while (str[0][i])
	{
		if (str[0][i] == '/')
			last = i;
		i++;
	}
	str[1] = ft_strsub(str[0], last, i - last);
	free(str[0]);
	ft_putstr("\033[3;94m");
	ft_putstr(str[1]);
	free(str[1]);
	ft_putstr("\033[0m");
	ft_putstr(" ");
	str[0] = get_usr();
	ft_str_add_prefixe("(", &str[0]);
	ft_str_add_suffix(&str[0], "):");
	ft_put_rainbow(str[0]);
	free(str[0]);
}

static void		*find_command(char *p_str)
{
	if (p_str == NULL)
		return (NULL);
	else if (ft_strcmp(p_str, "echo"))
		return (&mini_echo);
	else if (ft_strcmp(p_str, "pwd"))
		return (&mini_pwd);
	else if (ft_strcmp(p_str, "env"))
		return (&mini_env);
	else if (ft_strcmp(p_str, "export"))
		return (&mini_export);
	else if (ft_strcmp(p_str, "unset"))
		return (&mini_unset);
	else if (ft_strcmp(p_str, "cd"))
		return (&mini_cd);
	else if (ft_strcmp(p_str, "help"))
		return (&help);
	else if (ft_strnstr(p_str, "./", 2) || ft_strnstr(p_str, "../", 3) || ft_strnstr(p_str, "/", 1))
		return (&mini_exec);
	else if (ft_strcmp(p_str, "exit"))
		return (&mini_exit);
	else
	{
		ft_putstr(p_str);
		ft_putstr(": command not found\n");
		return (NULL);
	}
}

static void		apply_function(void (*f)(char **param), char **param)
{
	if (f == NULL)
		return ;
	f(param);
}

void	child_killer(int sig)
{
	char	*pwd;
	int	i;

	i = 0;
	(void)sig;
	close(g_env_fd[0]);
	while (g_env.data[i])
	{
		write(g_env_fd[1], g_env.data[i], ft_strlen(g_env.data[i]));
		write(g_env_fd[1], "\n", 1);
		i++;
	}
	pwd = get_pwd();
	write(g_env_fd[1], pwd, ft_strlen(pwd));
	free(pwd);
	close(g_env_fd[1]);
	if (sig != 1 && sig != 3)
		ft_putchar('\n');
	exit(sig);
}

static void		main_execution(void)
{
	char	*str;
	t_param *param;
	size_t	n;
	int		stdout;

	param = malloc_param();
	stdout = dup(1);
	print_prompt();
	if (get_next_line(0, &str))
	{
		signal(SIGQUIT, child_killer);
		n = 0;
		param = get_param(str);
		while (param->param[n])
		{
			apply_function(find_command(param->param[n][0]), param->param[n]);
			n++;
			dup2(stdout, 1);
		}
		free(str);
		n = 0;
		while (param->param[n])
		{
			ft_free_tab((void**)param->param[n]);
			n++;
		}
		child_killer(1);
	}
	mini_exit();
}

void take_environ(void)
{
	char	*str;
	int		ret;
	char	**tab;

	tab = (char	**)ft_tab_new(0);
	close(g_env_fd[1]);
	ret = 1;
	while ((ret = get_next_line(g_env_fd[0], &str)) != -1)
	{
		if (ret == 0)
		{
			destroy_t_char_list(g_env);
			g_env = create_char_list(ft_tab_len((void **)tab));
			g_env.data = (char **)ft_tab_cpy((void **)g_env.data, (void **)tab);
			free(tab);
			chdir(str);
			free(str);
			close(g_env_fd[0]);
			return ;
		}
		ft_add_to_tab((void *)str, (void ***)&tab);
	}
	ft_putstr("relink failed");
	exit (0);
}

void			forker(void)
{
	int status;
	int	pid;

	pid = 1;
	status = 2;
	while (pid != 0 && status != 0)
	{
		if (pipe(g_env_fd) == -1)
		{
			ft_putstr("relink failed");
			exit (0);
		}
		if ((pid = fork()) == -1)
			ft_putstr("fork failed");
		if (pid == 0)
		{
			signal(SIGINT, child_killer);
			main_execution();
		}
		else
		{
			waitpid(pid, &status, 0);
			if (status != 0)
				take_environ();
			if (status == 768)
					ft_putstr("minishell quit process\n");
		}
	}
}

int				main(int ac __attribute__((unused)),
								char **av __attribute__((unused)), char **env)
{
	set_environ(env);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	forker();
	return (0);
}
