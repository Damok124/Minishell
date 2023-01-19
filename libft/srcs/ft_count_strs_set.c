/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_strs_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:08:08 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/19 23:08:14 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_count_strs_set(const char *s, char *set)
{
	ssize_t	n;
	ssize_t	i;

	n = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] && ft_strchr(set, s[i]))
			i++;
		if (s[i] && !ft_strchr(set, s[i]))
			n++;
		while (s[i] && !ft_strchr(set, s[i]))
			i++;
	}
	return (n);
}
