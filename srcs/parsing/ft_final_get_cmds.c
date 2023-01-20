/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_get_cmds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:02:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_final_get_cmds(char **cmds, char **src, char **trans)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src && trans && src[i] && trans[i])
	{
		if (ft_iscmd(trans[i]))
		{
			cmds[j] = ft_strdup(src[i]);
			j++;
		}
		i++;
	}
}
