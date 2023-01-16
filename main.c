/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:56:10 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/16 16:37:27 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_child_id;

void	handler(int num)
{
	if (g_child_id != 0 && g_child_id != -1 && g_child_id != 33280)
	{
		g_child_id = -2;
		return ;
	}
	if (g_child_id == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		g_child_id = -1;
		exit(130);
		return ;
	}
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)num;
}

int	main(int argc, char **argv, char **env)
{
	char		*str;
	t_nod		*env_nod;

	str = NULL;
	g_child_id = -1;
	signal(SIGINT, handler);
	env_nod = ft_init_lst(env);
	while (1)
	{
		str = readline("Minishell:~");
		add_history(str);
		if (str != NULL)
			ft_execute(str, env_nod);
		if (str == NULL)
		{
			printf("exit");
			break ;
		}
		free(str);
	}
	ft_free_env(env_nod);
	(void)argc;
	(void)argv;
	return (0);
}

void	ft_free_env(t_nod *env)
{
	t_nod *tmp;

	while (env != NULL)
	{
		tmp = env;
		env = env->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}
