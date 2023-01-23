/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:33:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/23 17:56:34 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_parsed *lst, t_parsed *head, t_nod *env, int *tab)
{
	int		i;
	int		check;

	check = 1;
	if (lst && lst->cmds && lst->cmds[1])
	{
		i = ft_atoi_safe(lst->cmds[1], &check);
		if (check == 0)
		{
			printf("exit\n");
			printf("Minishell: exit: %s: numeric argument required\n",
				lst->cmds[1]);
			ft_clean_pipex(head, env, NULL, NULL);
			free(tab);
			exit(2);
		}
		i = 0;
		ft_check_exit_arg(lst, head, env, tab);
	}
	if (ft_exit_2(lst, head, env, tab) == 1)
		return ;
	ft_clean_pipex(head, env, NULL, NULL);
	free(tab);
	exit(0);
}

void	ft_check_exit_arg(t_parsed *lst, t_parsed *head, t_nod *env, int *tab)
{
	int	i;
	int	check;

	check = 1;
	i = 0;
	while (lst && lst->cmds && lst->cmds[1][i])
	{
		if (!ft_strisdigit(lst->cmds[1]))
		{
			printf("exit\n");
			printf("Minishell: exit: %s: numeric argument required\n",
				lst->cmds[1]);
			i = ft_atoi_safe(lst->cmds[1], &check);
			ft_clean_pipex(head, env, NULL, NULL);
			free(tab);
			exit(2);
		}
		i++;
	}
}

int	ft_exit_2(t_parsed *lst, t_parsed *head, t_nod *env, int *tab)
{
	int	i;
	int	check;

	check = 1;
	if (lst && lst->cmds && lst->cmds[1] && !lst->cmds[2])
	{
		printf("exit\n");
		i = ft_atoi_safe(lst->cmds[1], &check);
		ft_free_parsed(head);
		ft_free_env(env);
		free(tab);
		exit(i);
	}
	if (lst && lst->cmds && lst->cmds[1] && lst->cmds[2])
	{
		printf("exit\nMinishell: exit: too many arguments\n");
		lst = lst->next;
		return (1);
	}
	return (0);
}
