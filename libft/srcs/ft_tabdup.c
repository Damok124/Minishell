/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:25:49 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/30 13:11:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_tabdup(int len, int *src, int *dest)
{
	int	i;

	i = 0;
	dest = NULL;
	if (src)
	{
		dest = (int *)malloc(sizeof(int) * len);
		if (!dest)
			return (NULL);
		ft_memset(dest, 0, sizeof(int) * len);
		while (src && i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
