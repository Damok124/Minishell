/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:25:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/09 02:22:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_strs_to_tab(int len, char **strs)
{
	int	i;
	int	*tab;
	int	tester;

	i = -1;
	tester = 1;
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, sizeof(int) * len);
	while (tester > 0 && strs && strs[++i])
		tab[i] = ft_atoi_safe(strs[i], &tester);
	if (tester == 0)
	{
		if (tab)
			ft_true_free((void **)&tab);
		return (NULL);
	}
	return (tab);
}
