/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occurences_counter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:54:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_occurences_counter(char *big, char *little)
{
	int		i;
	int		total;
	int		big_len;
	int		little_len;
	char	*tmp;

	tmp = NULL;
	total = 0;
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	i = 0;
	while (big && big[i] && little && big_len >= little_len)
	{
		tmp = ft_strnstr(big + i, little, little_len);
		if (tmp)
		{
			i += little_len - 1;
			tmp = NULL;
			total++;
		}
		i++;
	}
	return (total);
}
