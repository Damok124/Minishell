/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clean_redirections.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:01:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lst_clean_redirections(t_twins *lst)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (lst)
	{
		ft_trim_trans(lst->src, lst->trans);
		while (lst->trans && lst->trans[i])
		{
			tmp = lst->src[i];
			lst->src[i] = ft_strtrim(tmp, "\a\b\t\n\v\f\r ");
			ft_true_free((void **)&tmp);
			i++;
		}
		i = 0;
		lst = lst->next;
	}
}
