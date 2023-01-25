/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_trans_symbol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/25 17:24:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lst_trans_symbol(t_twins *lst)
{
	char	*tmp;

	tmp = NULL;
	while (lst)
	{
		ft_trans_to_symbol(lst->src, lst->trans);
		lst = lst->next;
	}
}
