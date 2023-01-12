/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul_safe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:03:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/10 14:47:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long int	ft_atoul_safe2(const char *nptr, int *check, \
	unsigned long long int i, unsigned long long int j)
{
	int	k;

	k = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		*check = 0;
	else if (*nptr == '+' || (*nptr >= '0' && *nptr <= '9'))
		k = 1;
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
	return (i * k);
}

unsigned long int	ft_atoul_safe(const char *nptr, int *check)
{
	unsigned long long int	i;
	unsigned long long int	j;
	unsigned long int		ret;

	i = 0;
	j = i;
	ret = 0;
	if (nptr)
		ret = ft_atoul_safe2(nptr, check, i, j);
	return (ret);
}
