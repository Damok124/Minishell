/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:51:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/06 16:37:48 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_identifier(char *str, int type, int do_it)
{
	int	i;

	i = 0;
	if ((str[0] < 'A' || str[0] > 'z') && str[0] != '_')
	{
		ft_export_unset_error_message(str, type);
		return (1);
	}
	while (str[i] != '\0' && str[i] != '=')
		i++;
	if (ft_check_first_half(str) == 1)
	{
		ft_export_unset_error_message(str, type);
		return (1);
	}
	if (ft_check_middle_identifier(str + i - 1, type, do_it) == 1)
		return (1);
	return (0);
}

int	ft_check_first_half(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (str[i] == '_' || (str[i] == '+' && str[i + 1] == '='))
			;
		else if (str[i] < 48 && str[i])
			return (1);
		else if (str[i] > 57 && str[i] < 65)
			return (1);
		else if (str[i] > 90 && str[i] < 97)
			return (1);
		else if (str[i] > 122)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_middle_identifier(char *str, int type, int i)
{
	if (ft_check_number_export(str[0]) == 1
		|| (str[0] == '+' && ft_check_number_export(str[0]) == 1))
	{
		if (type == 0)
			ft_putstr_fd("minishell: export: `", 2);
		else
			ft_putstr_fd("minishell: unset: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
		(void)i;
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

void	ft_choose_export(t_nod *big_nod[3], int do_it, int check, char *str)
{
	if (do_it == 0 && check == 0 && ft_strchr(str, '=') == NULL)
		ft_add_to_export_no_value(big_nod[0], str);
	else if (do_it == 0 && check == 0 && ft_search_delimiter(str) == 1)
		ft_add_to_env_no_value(big_nod[0], str);
	else if (do_it == 0 && check == 0 && ft_search_delimiter(str) == 0)
		ft_add_basic(big_nod[0], str);
	else if (do_it == 0 && check == 0 && ft_search_delimiter(str) == 2)
		ft_add_basic_and_plus(big_nod[0], str);
}
