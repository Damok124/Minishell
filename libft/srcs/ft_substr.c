/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:49:49 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	ssize_t	j;
	char	*str;
	size_t	slen;

	i = start;
	j = -1;
	slen = ft_strlen(s);
	if (i > slen || len == 0)
	{
		str = calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		return (str);
	}
	if (len > (slen - i))
		str = malloc((sizeof(char) * (slen - i)) + 1);
	else
		str = malloc((sizeof(char) * len) + 1);
	if (!str)
		return (NULL);
	while (++j < (ssize_t)len && s[i + j])
		str[j] = s[i + j];
	str[j] = '\0';
	return (str);
}
