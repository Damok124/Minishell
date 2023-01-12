/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:39:26 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 21:22:53 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_printitoa(char *a, int n, size_t i)
{
	int	j;

	j = 0;
	a[i] = '\0';
	i--;
	if (n == 0)
		a[i] = 0 + '0';
	else
	{
		while (i != 0)
		{
			j = n % 10;
			if (j < 0)
				j *= -1;
			a[i] = (j + '0');
			n /= 10;
			i--;
		}
		if (n <= 0)
			a[0] = '-';
		else
			a[i] = n + '0';
	}
	return (a);
}

static size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		i;

	i = ft_intlen(n);
	a = malloc(sizeof(char) * i + 1);
	if (!a)
		return (NULL);
	a = ft_printitoa(a, n, i);
	return (a);
}
