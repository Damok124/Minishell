/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disable_no_name_var_env.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:10:25 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/05 13:49:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_disable_no_name_var_env(char **src, char **trans)
{
	int	i;

	i = 0;
	while (src && trans && src[0] && trans[0] && src[0][i] && trans[0][i])
	{
		if (trans[0][i] == '$' && trans[0][i + 1] && src[0][i + 1] && \
		(trans[0][i + 1] == ' ' || ft_strchr("\a\b\t\n\v\f\r ", src[0][i + 1])))
			trans[0][i] = '0';
		i++;
	}
}
