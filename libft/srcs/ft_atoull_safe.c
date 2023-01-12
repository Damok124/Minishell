/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:03:16 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 11:49:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long int	ft_atoull_safe(const char *nptr, int *check)
{
	unsigned long long int	i;
	unsigned long long int	j;

	i = 0;
	if (nptr)
	{
		while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
			nptr++;
		if (*nptr == '-')
			*check = 0;
		if (*nptr == '-' || *nptr == '+')
			nptr++;
		while (*nptr && *nptr >= '0' && *nptr <= '9')
		{
			j = i;
			i *= 10;
			i += *nptr - '0';
			if (j > i)
				*check = 0;
			nptr++;
		}
	}
	return (i);
}
