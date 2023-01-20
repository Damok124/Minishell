/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_on_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:00:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_split_on_spaces(t_twins *lst, char **src, char **trans)
{
	int	i;

	i = 0;
	while (lst && src && trans && src[i] && trans[i])
	{
		lst->trans = ft_split(trans[i], ' ');
		lst->src = ft_strsdup(lst->trans);
		ft_copy_without_spaces(lst->src, src[i], trans[i]);
		lst = lst->next;
		i++;
	}
}
