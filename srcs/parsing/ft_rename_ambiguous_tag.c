/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rename_ambiguous_tag.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:53:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_rename_ambiguous_tag(char **trans)
{
	int	i;

	i = 0;
	while (trans && trans[i])
	{
		if (trans[i][0] == '?')
		{
			if (trans[i][2] && trans[i][2] == '>')
				trans[i][1] = 'A';
			trans[i][2] = '\0';
		}
		i++;
	}
}
