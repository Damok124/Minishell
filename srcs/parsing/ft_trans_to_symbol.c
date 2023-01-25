/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_trans.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/25 17:31:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_trans_to_symbol(char **src, char **trans)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src && src[i] && trans && trans[i])
	{
		ft_replace_src_redir_symbols(src, trans, i);
		if (src[i][j] && trans[i][j] && trans[i][j] == '?')
		{
			while (src[i][j] && ft_strchr("<>", src[i][j]) && trans[i][j + 1])
			{
				trans[i][j + 1] = src[i][j];
				src[i][j] = ' ';
				j++;
			}
		}
		trans[i][j + 1] = '\0';
		j = 0;
		i++;
	}
	ft_rename_ambiguous_tag(trans);
}
