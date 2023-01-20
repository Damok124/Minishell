/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parallel_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:59:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_parallel_split(char **model, char *to_split)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	dest = ft_strsdup(model);
	while (model && model[i])
	{
		ft_strlcpy(dest[i], to_split + j, ft_strlen(dest[i]) + 1);
		j += ft_strlen(dest[i]) + 1;
		i++;
	}
	return (dest);
}
