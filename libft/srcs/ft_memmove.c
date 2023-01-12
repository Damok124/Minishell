/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:08:29 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 21:24:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destb;
	char	*srcb;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	destb = (char *)dest;
	srcb = (char *)src;
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (n--)
			destb[n] = srcb[n];
	}
	return (destb);
}
