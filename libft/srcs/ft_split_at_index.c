/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_at_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:07:18 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/19 23:07:28 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_split_at_index(char *str, int i)
{
	char	**final;
	char	*first;
	char	*last;

	final = NULL;
	if (str)
	{
		last = ft_strdup(str + i);
		str[i] = '\0';
		first = ft_strdup(str);
		final = (char **)malloc(sizeof(char *) * 3);
		if (!final)
			return (NULL);
		final[0] = first;
		final[1] = last;
		final[2] = NULL;
	}
	return (final);
}
