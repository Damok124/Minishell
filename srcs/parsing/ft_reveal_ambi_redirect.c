/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reveal_ambi_redirect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 17:46:03 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reveal_ambi_redirect(char **src, char **trans)
{
	int	j;
	int	i;

	i = -1;
	j = 0;
	while (src && trans && src[0] && trans[0] && src[0][++i] && trans[0][i])
	{
		if (ft_strchr("<>", trans[0][i]))
			j = 1;
		else if (trans[0][i] == 'A')
			j = 2;
		if (j)
		{
			while (src[0][i + j] && ft_isspace(src[0][i + j]))
				j++;
			while (trans[0][i + j] && ft_strchr("0\"\'", trans[0][i + j]))
				j++;
			if (trans[0][i + j] && trans[0][i + j] == '$')
			{
				trans[0][i + j] = '0';
				trans[0][i] = '?';
			}
			j = 0;
		}
	}
}
