/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_src_redir_symbols.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:34:17 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/25 17:35:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_src_redir_symbols(char **src, char **trans, int i)
{
	char	*tmp;

	tmp = NULL;
	if (ft_is_duo(trans[i]))
	{
		tmp = ft_strdup(src[i] + 2);
		ft_true_free((void **)&src[i]);
		src[i] = tmp;
	}
	else if (ft_is_solo(trans[i]))
	{
		tmp = ft_strdup(src[i] + 1);
		ft_true_free((void **)&src[i]);
		src[i] = tmp;
	}
}
