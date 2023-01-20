/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:06:59 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_format_quotes(char *trans, int size)
{
	int	i;
	int	quotes[2];

	i = 0;
	quotes[SIMPLE] = 0;
	quotes[DOUBLE] = 0;
	while (i < size && trans && trans[i])
	{
		if (trans[i] == '\'')
			quotes[SIMPLE]++;
		if (trans[i] == '\"')
			quotes[DOUBLE]++;
		i++;
	}
	if ((quotes[SIMPLE] % 2) != 0 || (quotes[DOUBLE] % 2) != 0)
		return (0);
	return (1);
}
