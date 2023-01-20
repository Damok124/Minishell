/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_twins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:58:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_twins(t_twins *lst)
{
	t_twins	*tmp;

	tmp = NULL;
	while (lst)
	{
		if (lst->src)
			ft_full_free((void **)lst->src);
		if (lst->trans)
			ft_full_free((void **)lst->trans);
		tmp = lst;
		lst = lst->next;
		ft_true_free((void **)&tmp);
	}
}
