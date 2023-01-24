/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/24 18:05:11 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_spaces(char **src, char **trans)
{
	int	i;

	i = 0;
	while (trans && trans[0] && trans[0][i])
	{
		if (i > 0 && ft_strchr("<>AH", trans[0][i]) \
			&& !ft_isspace(trans[0][i - 1]))
		{
			src[1] = ft_substr(src[0], 0, i);
			src[2] = ft_strdup(src[0] + i);
			src[3] = ft_strjoin(src[1], " ");
			src[4] = src[0];
			src[0] = ft_strjoin(src[3], src[2]);
			trans[1] = ft_substr(trans[0], 0, i);
			trans[2] = ft_strdup(trans[0] + i);
			trans[3] = ft_strjoin(trans[1], " ");
			trans[4] = trans[0];
			trans[0] = ft_strjoin(trans[3], trans[2]);
			ft_only_strs_free(src + 1);
			ft_only_strs_free(trans + 1);
			i = 0;
		}
		i++;
	}
}
