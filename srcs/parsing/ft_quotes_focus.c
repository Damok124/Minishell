/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_focus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:06:44 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_quotes_focus(char **src, char **trans, int i, int *quotes)
{
	if (src[0][i] == '\'' && (quotes[DOUBLE] % 2) == 0)
	{
		trans[0][i] = '\'';
		quotes[SIMPLE] += 1;
	}
	else if (src[0][i] == '\"' && (quotes[SIMPLE] % 2) == 0)
	{
		trans[0][i] = '\"';
		quotes[DOUBLE] += 1;
	}
}
