/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:33:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/27 17:38:23 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_parsed *lst[2], int print_check, t_nod *env, int *tab)
{
	int		i;
	int		check;

	check = 1;
	if (lst && lst[1]->cmds && lst[1]->cmds[1]
		&& ft_check_num(lst[1]->cmds[1]) == 0)
	{
		i = ft_atoi_safe(lst[1]->cmds[1], &check);
		if (check == 0)
		{
			if (print_check == 0)
				printf("exit\n");
			ft_error_msg(lst[1]);
			ft_clean_pipex(lst[0], env, NULL, NULL);
			ft_true_free((void **)&tab);
			exit(1);
		}
		i = 0;
		ft_check_exit_arg(lst, print_check, env, tab);
	}
	if (ft_exit_2(lst, print_check, env, tab) == 1)
		return (1);
	ft_clean_pipex(lst[0], env, NULL, NULL);
	ft_true_free((void **)&tab);
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
		if (ft_check_num(lst[1]->cmds[1]) == 0)
		{
			if (print_check == 0)
				printf("exit\n");
			ft_error_msg(lst[1]);
			i = ft_atoi_safe(lst[1]->cmds[1], &check);
			ft_clean_pipex(lst[0], env, NULL, NULL);
			ft_true_free((void **)&tab);
			exit(2);
		}
		i++;
	}
}

int	ft_exit_2(t_parsed *lst[2], int print_check, t_nod *env, int *tab)
{
	long int	i;
	int			check;

	check = 1;
	if (lst && lst[1]->cmds && lst[1]->cmds[1] && !lst[1]->cmds[2])
	{
		if (print_check == 0)
			printf("exit\n");
		i = ft_atol_safe1 (lst[1]->cmds[1], &check);
		ft_free_parsed(lst[0]);
		ft_free_env(env);
		ft_true_free((void **)&tab);
		if (check == 0)
		{
			ft_putstr_fd("bash: exit: : numeric argument required", 2);
			exit(2);
		}
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

long int	ft_long_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sign;
	int		tmp;

	i = 0;
	result = 0;
	sign = 1;
	tmp = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
		tmp++;
	}
	if (tmp > 1)
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - '0';
	result = result * sign;
	return (result);
}
