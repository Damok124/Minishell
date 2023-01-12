/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:59:19 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 11:49:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol_safe2(const char *nptr, int *check, long long i, long long j)
{
	int	k;

	k = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		k = -1;
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

long	ft_atol_safe1(const char *nptr, int *check)
{
	long long	i;
	long long	j;
	long		ret;

	i = 0;
	j = i;
	ret = 0;
	if (nptr)
		ret = ft_atol_safe2(nptr, check, i, j);
	return (ret);
}
