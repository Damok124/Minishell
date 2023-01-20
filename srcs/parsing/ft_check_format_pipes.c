/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_pipes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:09:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_format_pipes(char *trans)
{
	int	i;

	i = 0;
	while (trans && trans[i] && ft_isspace(trans[i]))
		i++;
	if (trans [i] && trans[i] == '|')
		return (0);
	while (trans && trans[i])
	{
		if (i && trans[i] && trans[i] == '|')
		{
			i++;
			while (trans[i] && trans[i] == ' ')
				i++;
			if (!trans[i] || (trans[i] && trans[i] == '|'))
				return (0);
			i--;
		}
		i++;
	}
	return (1);
}
