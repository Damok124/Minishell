/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:56:10 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/19 18:00:13 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_child_id;

void	handler(int num)
{
	if (g_child_id != 0 && g_child_id != -1 && g_child_id
		!= 33280 && g_child_id != 130)
	{
		if (g_child_id == 1)
			write(1, "\n", 1);
		g_child_id = -1;
		return ;
	}
	if (g_child_id == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		g_child_id = 666;
		close(0);
		return ;
	}
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_child_id = 130;
	(void)num;
}

int	main(int argc, char **argv, char **env)
{
	t_nod		*env_nod;

	g_child_id = -1;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	env_nod = ft_init_lst(env);
	ft_while(env_nod);
	ft_free_env(env_nod);
	(void)argc;
	(void)argv;
	return (0);
}

void	ft_while(t_nod *env_nod)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = readline("Minishell:~");
		if (g_child_id == 130)
		{
			g_child_id = -1;
			ft_return_value(130, env_nod);
		}
		add_history(str);
		g_child_id = 1;
		if (str != NULL)
			ft_execute(str, env_nod);
		g_child_id = -1;
		if (str == NULL)
		{
			printf("exit");
			break ;
		}
		free(str);
	}
}

void	ft_return_value(int value, t_nod *env)
{
	char	*tmp;

	tmp = ft_itoa(value);
	while (env != NULL)
	{
		if (ft_strncmp(env->key, "LEC_RV", 7) == 0)
		{
			free(env->value);
			env->value = tmp;
			return ;
		}
		env = env->next;
	}
}

void	ft_free_env(t_nod *env)
{
	t_nod	*tmp;

	while (env != NULL)
	{
		tmp = env;
		env = env->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}
