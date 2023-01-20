/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rename_angl_brackets.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:53:26 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_rename_angl_brackets(char **trans)
{
	int	i;

	i = 0;
	while (trans && trans[0] && trans[0][i] && trans[0][i + 1])
	{
		if (trans[0][i] == '<' && trans[0][i + 1] == '<')
		{
			trans[0][i] = 'H';
			trans[0][i + 1] = '0';
			i++;
		}
		else if (trans[0][i] == '>' && trans[0][i + 1] == '>')
		{
			trans[0][i] = 'A';
			trans[0][i + 1] = '0';
			i++;
		}
		i++;
	}
}
