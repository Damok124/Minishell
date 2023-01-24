/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_free_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:28:23 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/24 18:03:16 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_full_free_lst(t_list **list)
{
	t_list	*tmp;

	tmp = NULL;
	while (*list)
	{
		(*list)->content = NULL;
		tmp = (*list)->next;
		(*list)->next = NULL;
		ft_true_free((void **)list);
		*list = tmp;
	}
}
