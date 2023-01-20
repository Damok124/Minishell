/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lst_twins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:59:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_twins	*ft_init_lst_twins(int size)
{
	t_twins	*elem;

	if (size)
	{
		elem = (t_twins *)malloc(sizeof(t_twins));
		if (!elem)
			return (NULL);
		elem->src = NULL;
		elem->trans = NULL;
		elem->next = ft_init_lst_twins(size -1);
		return (elem);
	}
	return (NULL);
}
