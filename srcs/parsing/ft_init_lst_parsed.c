/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lst_parsed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:01:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parsed	*ft_init_lst_parsed(int size)
{
	t_parsed	*elem;

	if (size)
	{
		elem = (t_parsed *)malloc(sizeof(t_parsed));
		if (!elem)
			return (NULL);
		elem->empty = 1;
		elem->cmds = NULL;
		elem->redirections = NULL;
		elem->cmds_quant = 0;
		elem->redir_quant = 0;
		elem->hdocs_quant = 0;
		elem->next = ft_init_lst_parsed(size -1);
		return (elem);
	}
	return (NULL);
}
