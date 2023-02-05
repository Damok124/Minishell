/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disable_no_name_var_env.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:10:25 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/04 20:10:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_disable_no_name_var_env(char **trans)
{
	int	i;

	i = 0;
	while (trans && trans[0] && trans[0][i])
	{
		if (trans[0][i] == '$' && trans[0][i + 1] && trans[0][i + 1] == ' ')
			trans[0][i] = '0';
		i++;
	}
}
