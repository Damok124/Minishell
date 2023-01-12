/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 06:59:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 21:24:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	size_t			i;
	unsigned char	uc;

	str = (void *)s;
	i = 0;
	while (n)
	{
		uc = str[i];
		if ((uc - (unsigned char) c) == 0)
		{
			return (&str[i]);
		}
		n--;
		i++;
	}
	return (NULL);
}
