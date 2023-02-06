/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:33:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/06 18:17:11 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_core *core, int print_check, t_nod *env, int *tab)
{
	int		i;
	int		check;

	check = 1;
	if (core->lst[1]->cmds && core->lst[1]->cmds[1]
		&& ft_check_num(core->lst[1]->cmds[1]) == 0)
	{
		i = ft_atoi_safe(core->lst[1]->cmds[1], &check);
		if (check == 0)
		{
			if (print_check == 0)
				printf("exit\n");
			ft_error_msg(core->lst[1]);
			ft_clean_exit(core->lst[0], env, core->p1);
			ft_true_free((void **)&tab);
			exit(1);
		}
		ft_check_exit_arg(core, print_check, env, tab);
	}
	if (ft_exit_2(core, print_check, env, tab) == 1)
		return (1);
	i = ft_atoi(ft_get_env("LEC_RV", env));
	ft_clean_exit(core->lst[0], env, core->p1);
	ft_true_free((void **)&tab);
	exit(i);
}

void	ft_check_exit_arg(t_core *core, int print_check,
			t_nod *env, int *tab)
{
	int	i;
	int	check;

	check = 1;
	i = 0;
	while (core->lst[1]->cmds && core->lst[1]->cmds[1][i])
	{
		if (ft_check_num(core->lst[1]->cmds[1]) == 0)
		{
			if (print_check == 0)
				printf("exit\n");
			ft_error_msg(core->lst[1]);
			i = ft_atoi_safe(core->lst[1]->cmds[1], &check);
			ft_clean_exit(core->lst[0], env, core->p1);
			ft_true_free((void **)&tab);
			ft_close(core->p1[0], core->p1[1], -1, -1);
			exit(2);
		}
		i++;
	}
}

int	ft_exit_2(t_core *core, int print_check, t_nod *env, int *tab)
{
	long int	i;
	int			check;

	check = 1;
	if (core->lst[1]->cmds && core->lst[1]->cmds[1] && !core->lst[1]->cmds[2])
	{
		i = ft_atol_safe1 (core->lst[1]->cmds[1], &check);
		ft_print_exit_error(core, print_check, &check);
		ft_clean_exit(core->lst[0], env, core->p1);
		ft_true_free((void **)&tab);
		ft_close(core->p1[0], core->p1[1], -1, -1);
		if (check == 0)
		{
			ft_putstr_fd("bash: exit: : numeric argument required\n", 2);
			exit(2);
		}
		exit(i);
	}
	if (core->lst[1]->cmds && core->lst[1]->cmds[1] && core->lst[1]->cmds[2])
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
