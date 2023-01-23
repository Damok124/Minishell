/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:33:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/23 19:48:09 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_parsed *lst[2], int print_check, t_nod *env, int *tab)
{
	int		i;
	int		check;

	check = 1;
	if (lst && lst[1]->cmds && lst[1]->cmds[1])
	{
		i = ft_atoi_safe(lst[1]->cmds[1], &check);
		if (check == 0)
		{
			if (print_check == 0)
				printf("exit\n");
			printf("Minishell: exit: %s: numeric argument required\n",
				lst[1]->cmds[1]);
			ft_clean_pipex(lst[0], env, NULL, NULL);
			free(tab);
			exit(2);
		}
		i = 0;
		ft_check_exit_arg(lst, print_check, env, tab);
	}
	if (ft_exit_2(lst, print_check, env, tab) == 1)
		return ;
	ft_clean_pipex(lst[0], env, NULL, NULL);
	free(tab);
	exit(0);
}

void	ft_check_exit_arg(t_parsed *lst[2], int print_check,
			t_nod *env, int *tab)
{
	int	i;
	int	check;

	check = 1;
	i = 0;
	while (lst && lst[1]->cmds && lst[1]->cmds[1][i])
	{
		if (!ft_strisdigit(lst[1]->cmds[1]))
		{
			if (print_check == 0)
				printf("exit\n");
			printf("Minishell: exit: %s: numeric argument required\n",
				lst[1]->cmds[1]);
			i = ft_atoi_safe(lst[1]->cmds[1], &check);
			ft_clean_pipex(lst[0], env, NULL, NULL);
			free(tab);
			exit(2);
		}
		i++;
	}
}

int	ft_exit_2(t_parsed *lst[2], int print_check, t_nod *env, int *tab)
{
	int	i;
	int	check;

	check = 1;
	if (lst && lst[1]->cmds && lst[1]->cmds[1] && !lst[1]->cmds[2])
	{
		if (print_check == 0)
			printf("exit\n");
		i = ft_atoi_safe(lst[1]->cmds[1], &check);
		ft_free_parsed(lst[0]);
		ft_free_env(env);
		free(tab);
		exit(i);
	}
	if (lst && lst[1]->cmds && lst[1]->cmds[1] && lst[1]->cmds[2])
	{
		printf("exit\nMinishell: exit: too many arguments\n");
		lst[1] = lst[1]->next;
		return (1);
	}
	return (0);
}
