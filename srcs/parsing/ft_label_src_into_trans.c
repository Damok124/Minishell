/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label_src_into_trans.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:03:49 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_label_src_into_trans(char **src, char **trans)
{
	int	i;
	int	quotes[2];

	i = 0;
	quotes[SIMPLE] = 0;
	quotes[DOUBLE] = 0;
	while (src[0] && src[0][i])
	{
		ft_quotes_focus(src, trans, i, quotes);
		ft_angled_brackets_focus(src, trans, i);
		ft_pipes_focus(src, trans, i, quotes);
		ft_var_env_focus(src, trans, i, quotes[SIMPLE]);
		ft_spaces_focus(src, trans, i, quotes);
		i++;
	}
}
