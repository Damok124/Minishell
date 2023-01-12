/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:15:02 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*p;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (c > 127)
		c -= 128;
	p = (char *)s;
	while (i <= len)
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
