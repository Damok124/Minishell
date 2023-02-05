/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_symbol_var_env.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/04 19:42:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_remove_symbol_var_env(char **src, char **trans, int i)
{
	while (src && src[0] && src[0][i] && ft_isspace(src[0][i]))
		i++;
	while (src && src[0] && src[0][i] && trans && trans[0] && trans[0][i] \
		&& !ft_strchr("<>|$", trans[0][i]) && !ft_isspace(src[0][i]))
	{
		if (trans[0][i] == '\"')
		{
			i++;
			while (trans[0][i] && trans[0][i] != '\"')
				i++;
		}
		else if (trans[0][i] == '\'')
		{
			i++;
			while (trans[0][i] && trans[0][i] != '\'')
				i++;
		}
		i++;
	}
	if (src && src[0] && trans && trans[0] && src[0][i] && trans[0][i] == '$')
		trans[0][i] = '0';
}
