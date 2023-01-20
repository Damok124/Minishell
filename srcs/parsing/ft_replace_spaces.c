/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_spaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:09:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_spaces(char **trans)
{
	int	i;

	i = 0;
	while (trans && trans[0] && trans[0][i])
	{
		if (ft_strchr("<>", trans[0][i]) && trans[0][i + 1] == ' ')
		{
			while (trans[0][i + 1] && trans[0][i + 1] == ' ')
			{
				trans[0][i + 1] = '0';
				i++;
			}
			i -= 1;
		}
		i++;
	}
}
