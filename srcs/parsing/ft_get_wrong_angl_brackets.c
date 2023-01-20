/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_wrong_angl_brackets.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:07:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_get_wrong_angl_brackets(void)
{
	char	**needle;

	needle = (char **)malloc(sizeof(char *) * 5);
	if (!needle)
		return (NULL);
	needle[0] = ft_strdup("<<<");
	needle[1] = ft_strdup(">>>");
	needle[2] = ft_strdup("><");
	needle[3] = ft_strdup("<>");
	needle[4] = NULL;
	return (needle);
}
