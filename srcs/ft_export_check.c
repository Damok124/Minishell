/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:51:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/02 18:50:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_identifier(char *str, int type, int do_it)
{
	int	i;
	int	no_value;

	i = 0;
	no_value = 0;
	if ((str[0] < 'A' || str[0] > 'z') && str[0] != '_')
	{
		if (do_it == 0)
		{
			if (type == 0)
				ft_putstr_fd("minishell: export: `", 2);
			else
				ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}
		return (1);
	}
	while (str[i] != '\0' && str[i] != '=')
		i++;
	if (str[i] == '\0')
		no_value = 1;
	if (ft_check_middle_identifier(str + i - 1, type, do_it, no_value) == 1)
		return (1);
	return (0);
}

int	ft_check_middle_identifier(char *str, int type, int i, int no_value)
{
	if (no_value == 0 && ft_check_number_export(str[0]) == 1)
	{
		if (i == 0)
		{
			if (type == 0)
				ft_putstr_fd("minishell: export: `", 2);
			else
				ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}
		return (1);
	}
	return (0);
}

int	ft_check_number_export(char c)
{
	if (c == '_' || c == '+')
		return (0);
	if (c < 48 || c > 122)
		return (1);
	if (c > 57 && c < 65)
		return (1);
	if (c > 90 && c < 97)
		return (1);
	return (0);
}
