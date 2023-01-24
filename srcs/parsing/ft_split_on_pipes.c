/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_on_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/24 17:55:18 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_split_on_pipes(t_twins *origin)
{
	char	*src;
	char	*trans;

	src = ft_strdup(origin->src[0]);
	trans = ft_strdup(origin->trans[0]);
	ft_full_free((void **)origin->src);
	ft_full_free((void **)origin->trans);
	origin->trans = ft_split(trans, '|');
	origin->src = ft_mirror_split(src, origin->trans);
	ft_true_free((void **)&src);
	ft_true_free((void **)&trans);
}
