/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/25 17:17:41 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lst_to_final(t_twins *lst, t_parsed *final)
{
	while (lst && final)
	{
		final->cmds_quant = ft_count_cmds(lst->trans);
		final->redir_quant = ft_count_redirections(lst->trans);
		final->hdocs_quant = ft_count_heredocs(lst->trans);
		if (final->cmds_quant)
		{
			final->cmds = ft_alloc_strs(final->cmds_quant);
			if (final->cmds)
				ft_final_get_cmds(final->cmds, lst->src, lst->trans);
		}
		if (final->redir_quant)
		{
			final->redirections = ft_alloc_strs(final->redir_quant);
			if (final->redirections)
				ft_final_get_redir(final->redirections, lst->src, lst->trans);
		}
		final->empty = final->cmds_quant + final->redir_quant;
		if (final->empty)
			final->empty = 0;
		else
			final->empty = 1;
		lst = lst->next;
		final = final->next;
	}
}
