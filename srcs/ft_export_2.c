/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:32:06 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/27 16:02:22 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_minus_before(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i][0] > '0' && str[i][0] < '9')
		{
			ft_putstr_fd("Minishell: export: not a valid identifier\n", 2);
			return (1);
		}
		while (str[i][j] != '=' && str[i][j] != '\0')
			j++;
		if (str[i][j] == '=' && (str[i][j - 1] == '-' || str[i][j - 1] == '\0'))
		{
			ft_putstr_fd("Minishell: export: not a valid identifier\n", 2);
			return (1);
		}
		i++;
		j = 0;
	}
	return (0);
}
