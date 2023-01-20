/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_lst_parsed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:03:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_show_lst_parsed(t_parsed *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("\nindex parsed %d:\n", i);
		printf("cmds  :");
		ft_show_strs(lst->cmds);
		printf("\n");
		printf("redir :");
		ft_show_strs(lst->redirections);
		printf("\n");
		printf("empty :%d; ", lst->empty);
		printf("cmds_quant :%d; ", lst->cmds_quant);
		printf("redir_quant :%d; ", lst->redir_quant);
		printf("hdoc_quant :%d\n", lst->hdocs_quant);
		lst = lst->next;
		i++;
	}
}
