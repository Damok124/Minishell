/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_trans.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:01:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_trim_trans(char **src, char **trans)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src && src[i] && trans && trans[i])
	{
		if (ft_is_duo(trans[i]) || ft_is_solo(trans[i]))
			src[i][0] = ' ';
		if (ft_is_duo(trans[i]))
			src[i][1] = ' ';
		if (src[i][j] && trans[i][j] && trans[i][j] == '?')
		{
			while (src[i][j] && ft_strchr("<>", src[i][j]) && trans[i][j + 1])
			{
				trans[i][j + 1] = src[i][j];
				src[i][j] = ' ';
				j++;
			}
		}
		trans[i][j + 1] = '\0';
		j = 0;
		i++;
	}
	ft_rename_ambiguous_tag(trans);
}
