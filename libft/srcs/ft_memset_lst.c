/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:28:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/05 17:09:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memset_lst(t_list **list, void *content)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		tmp->content = content;
		tmp = tmp->next;
	}
}
