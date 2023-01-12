/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:53:26 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:50:03 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				j;
	unsigned int	k;
	char			*str;

	i = 0;
	j = 0;
	k = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) *(k + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i + j] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
