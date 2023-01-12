/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_intlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:40:43 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/06 18:48:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_index_intlst(t_list **astack, int *sortedav, int ac)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *astack;
	while (tmp)
	{
		tmp->index = 0;
		while (i < ac && tmp->index == 0)
		{
			if (*(int *)tmp->content == sortedav[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
		i = 0;
	}
}
