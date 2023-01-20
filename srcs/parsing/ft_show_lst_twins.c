/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_lst_twins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:00:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_show_lst_twins(t_twins *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("index lst %d :\n", i);
		ft_show_duo_strs(lst->src, lst->trans);
		lst = lst->next;
		i++;
	}
}
