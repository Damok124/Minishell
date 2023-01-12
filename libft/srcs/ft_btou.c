/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:03:20 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/21 01:25:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_btou(const char *nptr, char *base)
{
	unsigned int	ret;
	int				i;
	int				len;

	len = ft_strlen(base);
	i = 0;
	ret = 0;
	if (nptr)
	{
		while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
			nptr++;
		if (*nptr == '+')
			nptr++;
		while (*nptr && ft_strchr(base, *nptr))
		{
			ret *= len;
			while (base[i] != *nptr)
				i++;
			ret += i;
			i = 0;
			nptr++;
		}
	}
	return (ret);
}
