/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:56:10 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/09 14:47:37 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*g_prompt;

void	handler(int num)
{
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, g_prompt, ft_strlen(g_prompt));
	(void)num;
}

int	main(int argc, char **argv, char **env)
{
	char		*str;
	t_nod		*env_nod;

	return (0);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	env_nod = ft_init_lst(env);
	g_prompt = ft_get_username(env_nod);
	while (1)
	{
		str = readline(g_prompt);
		add_history(str);
		if (ft_strncmp(str, "echo", 4) == 0)
			ft_echo(ft_split(str, ' '));
		if (ft_strncmp(str, "cd", 2) == 0)
			ft_cd(ft_split(str, ' '), env_nod);
		if (ft_strncmp(str, "pwd", 3) == 0)
			ft_pwd(ft_split(str, ' '));
		if (ft_strncmp(str, "exit", 4) == 0)
			exit(0);
		if (ft_strncmp(str, "env", 3) == 0)
			ft_env(env_nod);
		if (ft_strncmp(str, "unset", 5) == 0)
			ft_unset(ft_split(str, ' '), env_nod);
		if (ft_strncmp(str, "export", 6) == 0)
			ft_export(ft_split(str, ' '), env_nod);
		free(str);
		if (str == NULL)
		{
			printf("exit hey");
			break ;
		}
	}
	(void)argc;
	(void)argv;
	return (0);
}

/*void	ft_zied(void)
{
	char	*cmdline;
	int		fd;

	fd = open("cmdline", O_RDONLY);
	cmdline = get_next_line(fd);
	ft_printf("%s", cmdline);
	ft_minishell_parsing(cmdline);
	close(fd);
}*/
