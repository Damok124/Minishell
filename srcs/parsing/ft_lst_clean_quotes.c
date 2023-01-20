/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clean_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:00:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lst_clean_quotes(t_twins *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		while (lst->trans[i])
		{
			ft_lst_remove_quotes(lst->src, lst->trans, i);
			i++;
		}
		i = 0;
		lst = lst->next;
	}
}
