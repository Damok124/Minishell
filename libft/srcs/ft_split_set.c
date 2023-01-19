/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:05:35 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/19 23:08:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_true_split_set(char const *s, char **str, char *set, ssize_t len)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	a;

	a = 0;
	i = 0;
	j = 0;
	while (s[i] && a < len)
	{
		while (s[i + j] && ft_strchr(set, s[i + j]))
			i++;
		while ((s[i + j] && !ft_strchr(set, s[i + j])))
			j++;
		if (ft_strchr(set, s[i + j]) || s[i + j] == 0)
			str[a] = ft_substr(s, i, j);
		a++;
		i = i + j;
		j = 0;
	}
}

char	**ft_split_set(const char *s, char *set)
{
	char	**strs;
	ssize_t	len;

	strs = NULL;
	if (s)
	{
		len = ft_count_strs_set(s, set);
		strs = (char **)malloc(sizeof(char *) * (len + 1));
		if (!strs)
			return (NULL);
		strs[len] = NULL;
		ft_true_split_set(s, strs, set, len);
	}
	return (strs);
}
