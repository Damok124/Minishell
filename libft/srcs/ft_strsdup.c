/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:07:33 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/19 23:07:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsdup(char **src)
{
	char	**dest;
	int		i;

	i = 0;
	while (src && src[i])
		i++;
	dest = ft_alloc_strs(i);
	while (--i >= 0)
		dest[i] = ft_strdup(src[i]);
	return (dest);
}
