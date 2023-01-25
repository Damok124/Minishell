/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_strtrim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:19:54 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/25 17:20:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_begin_strtrim(char const *s1, char const *set)
{
	char	*str;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (s1)
	{
		while (s1 && s1[i] && ft_strchr(set, s1[i]))
			i++;
		str = ft_strdup(s1 + i);
		if (str)
			return (str);
	}
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}
