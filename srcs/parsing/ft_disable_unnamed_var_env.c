/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disable_unnamed_var_env.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:54:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/26 18:54:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_disable_unnamed_var_env(char **trans)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (trans && trans[0][i])
	{
		if (trans[0][i] == '\"')
			quotes++;
		if (trans[0][i] && trans[0][i] == '$' && trans[0][i + 1] \
			&& trans[0][i + 1] == '\"' && (quotes % 2) != 0)
			trans[0][i] = '0';
		i++;
	}
}
