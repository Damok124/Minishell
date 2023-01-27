/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:32:06 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/27 18:53:16 by tlarraze         ###   ########.fr       */
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
		if ((str[i][0] > '0' && str[i][0] < '9')
				|| ft_check_first_export(str, i) == 1)
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

int	ft_check_first_export(char **str, int i)
{
	if (str[i][0] == '+' || str[i][0] == '-' || str[i][0] == '=')
		return (1);
	return (0);
}

void	ft_add_declare(t_nod *nod[3], char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(str[i], '=') != NULL)
		{
			// nod[2] = (t_nod *)malloc(sizeof(t_nod));
			// nod[2]->key = ft_strdup(str[i]);
			// nod[2]->value = NULL;
			// nod[2]->declare = 1;
			// nod[2]->next = NULL;
			// nod[1]->next = nod[2];
		}
		nod[1] = nod[0];
		i++;
	}
}
