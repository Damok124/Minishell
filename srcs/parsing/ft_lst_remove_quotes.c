/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:00:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lst_remove_quotes(char **src, char **trans, int i)
{
	int	j;

	j = 0;
	while (trans[i][j])
	{
		if (ft_isquotes(trans[i][j]))
		{
			while (trans[i][j])
			{
				trans[i][j] = trans[i][j + 1];
				src[i][j] = src[i][j + 1];
				j++;
			}
			j = -1;
		}
		j++;
	}
}
