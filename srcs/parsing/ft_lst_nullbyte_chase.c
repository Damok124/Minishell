/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_nullbyte_chase.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:23:21 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/25 19:23:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lst_nullbyte_chase(t_twins *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		while (lst->trans[i] && lst->src[i])
		{
			if (!lst->trans[i][0] && !lst->src[i][0])
				lst->trans[i][0] = '0';
			i++;
		}
		i = 0;
		lst = lst->next;
	}
}
