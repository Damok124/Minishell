/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:09:10 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 21:23:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			if (tmp2 != NULL)
				ft_lstclear(&tmp2, del);
			return (NULL);
		}
		ft_lstadd_back(&tmp2, tmp);
		if (tmp2 == NULL)
			tmp2 = tmp;
		lst = lst->next;
	}
	return (tmp2);
}
