/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:10:01 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 21:24:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*desti;
	char	*source;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	desti = dest;
	source = (char *) src;
	while (i < n)
	{
		desti[i] = source[i];
		i++;
	}
	return (dest);
}
