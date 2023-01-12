/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:25:45 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/30 13:12:47 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_sort_int_tab(int *tab, int size)
{
	int	*ret;
	int	i;
	int	n;

	ret = NULL;
	ret = ft_tabdup(size, tab, ret);
	i = 0;
	n = 0;
	while (ret && i + 1 < size)
	{
		if (ret[i] > ret[i + 1])
		{
			n = ret[i];
			ret[i] = ret[i + 1];
			ret [i + 1] = n;
			i = 0;
		}
		else
			i++;
	}
	return (ret);
}
