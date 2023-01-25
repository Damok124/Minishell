/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_to_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:13:45 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/25 17:14:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redir_to_clean(char **src, char **trans)
{
	int		i;

	i = 0;
	while (src && trans && src[0] && trans[0] && trans[0][i] && src[0][i])
	{
		if (ft_strchr("<>", trans[0][i]) && trans[0][i + 1] == ' ')
		{
			ft_clean_redir(trans, i + 1, " ");
			ft_clean_redir(src, i + 1, "\a\b\t\n\v\f\r ");
		}
		if (ft_strchr("AH", trans[0][i]) && trans[0][i + 2] == ' ')
		{
			ft_clean_redir(trans, i + 2, " ");
			ft_clean_redir(src, i + 2, "\a\b\t\n\v\f\r ");
		}
		i++;
	}
}
