/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parsed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:05:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_parsed(t_parsed *lst)
{
	t_parsed	*tmp;

	while (lst)
	{
		if (lst->cmds)
			ft_full_free((void **)lst->cmds);
		if (lst->redirections)
			ft_full_free((void **)lst->redirections);
		tmp = lst;
		lst = lst->next;
		ft_true_free((void **)&tmp);
	}
}
