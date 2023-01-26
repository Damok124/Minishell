/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:33:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/26 19:11:04 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_parsed *lst[2], int print_check, t_nod *env, int *tab)
{
	int		i;
	int		check;
	char	*str;
	char	*str_2;

	check = 1;
	if (lst && lst[1]->cmds && lst[1]->cmds[1])
	{
		i = ft_atoi_safe(lst[1]->cmds[1], &check);
		if (check == 0)
		{
			if (print_check == 0)
				printf("exit\n");
			str = ft_strjoin("Minishell: exit: ", lst[1]->cmds[1]);
			str_2 = ft_strjoin(str, ": numeric argument required\n");
			ft_putstr_fd(str_2, 2);
			free(str);
			free(str_2);
			ft_clean_pipex(lst[0], env, NULL, NULL);
			ft_true_free((void **)&tab);
			exit(2);
		}
		i = 0;
		ft_check_exit_arg(lst, print_check, env, tab);
	}
	if (ft_exit_2(lst, print_check, env, tab) == 1)
		return ;
	ft_clean_pipex(lst[0], env, NULL, NULL);
	ft_true_free((void **)&tab);
	exit(0);
}

void	ft_check_exit_arg(t_parsed *lst[2], int print_check,
			t_nod *env, int *tab)
{
	int	i;
	int	check;
	char	*str;
	char	*str_2;

	check = 1;
	i = 0;
	while (lst && lst[1]->cmds && lst[1]->cmds[1][i])
	{
		if (ft_check_num(lst[1]->cmds[1]) == 0)
		{
			if (print_check == 0)
				printf("exit\n");
			str = ft_strjoin("Minishell: exit: ", lst[1]->cmds[1]);
			str_2 = ft_strjoin(str, ": numeric argument required\n");
			ft_putstr_fd(str_2, 2);
			free(str);
			free(str_2);
			i = ft_atoi_safe(lst[1]->cmds[1], &check);
			ft_clean_pipex(lst[0], env, NULL, NULL);
			ft_true_free((void **)&tab);
			exit(i);
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
		ft_true_free((void **)&tab);
		exit(i);
	}
	if (lst && lst[1]->cmds && lst[1]->cmds[1] && lst[1]->cmds[2])
	{
		printf("exit\n");
		ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
		return (1);
	}
	return (0);
}

int	ft_check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9' && str[i] != '+' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}