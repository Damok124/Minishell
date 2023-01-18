/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:42:46 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/18 18:40:12 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//reproduce echo
void	ft_echo(char **str)
{
	int	i;

	i = 1;
	if (!str[1])
	{
		printf("\n");
		return ;
	}
	if (ft_strncmp(str[0], "echo", 5) == 0 && ft_check_echo_n(str[1]) == 0)
		ft_echo_n(str);
	else
	{
		while (str[i] != NULL)
		{
			if (str[i + 1] != NULL)
				printf("%s ", str[i]);
			if (str[i + 1] == NULL)
				printf("%s\n", str[i]);
			i++;
		}
	}
}

void	ft_echo_n(char **str)
{
	int	i;

	i = 2;
	while (str[i] != NULL && ft_check_echo_n(str[i]) == 0)
		i++;
	while (str[i] != NULL)
	{
		if (str[i + 1] != NULL)
			printf("%s ", str[i]);
		if (str[i + 1] == NULL)
			printf("%s", str[i]);
		i++;
	}
}

int	ft_check_echo_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (1);
	i++;
	while (str[i] != '\0')
	{
		if (str[i] != 'n' && str[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}
