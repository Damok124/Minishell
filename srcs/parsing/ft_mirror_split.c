/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mirror_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:59:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_mirror_split(char *src, char **trans)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = NULL;
	if (((ft_strslen(trans) - 1) + ft_sum_strlen(trans)) == (int)ft_strlen(src))
	{
		dest = ft_strsdup(trans);
		while (trans && trans[i])
		{
			while (trans[i][j])
			{
				dest[i][j] = src[j];
				j++;
			}
			src += j + 1;
			j = 0;
			i++;
		}
	}
	return (dest);
}
