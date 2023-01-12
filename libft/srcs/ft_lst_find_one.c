/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:34:18 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:42:21 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_find_one(t_list *lst, int position)
{
	while (position && lst && lst->next)
	{
		lst = lst->next;
		position--;
	}
	return (lst);
}
