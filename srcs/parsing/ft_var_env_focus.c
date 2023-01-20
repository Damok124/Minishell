/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_env_focus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:53:59 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_var_env_focus(char **src, char **trans, int i, int s_quotes)
{
	int	len;

	len = ft_strlen(src[0]);
	if ((i == 0 && src[0][i] == '$' && len > 1) \
		|| (i != (len - 1) && src[0][i] == '$' && (s_quotes % 2) == 0))
	{
		if (i > 0 && trans[0][i - 1] && trans[0][i - 1] == '$' \
			&& src[0][i] == '$')
			trans[0][i - 1] = '0';
		trans[0][i] = src[0][i];
	}
}
