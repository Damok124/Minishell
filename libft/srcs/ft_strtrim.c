/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:55:26 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/19 22:55:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)//update libft
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
		while (s1 && s1[i] && ft_strrchr(set, s1[j]))
			j--;
		str = ft_substr(s1, i, (j - i + 1));
		if (str)
			return (str);
	}
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}
