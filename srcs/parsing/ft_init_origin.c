/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_origin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:58:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_twins	*ft_init_origin(t_twins *origin, char *str1)
{
	origin = (t_twins *)malloc(sizeof(t_twins));
	if (!origin)
		return (NULL);
	origin->src = (char **)malloc(sizeof(char *) * 6);
	if (!origin->src)
	{
		ft_true_free((void **)&origin);
		return (NULL);
	}
	origin->trans = (char **)malloc(sizeof(char *) * 6);
	if (!origin->trans)
	{
		ft_full_free((void **)origin->src);
		ft_true_free((void **)&origin);
		return (NULL);
	}
	origin->src[0] = str1;
	origin->src[1] = NULL;
	origin->src[5] = NULL;
	origin->trans[0] = ft_twin_str(str1);
	origin->trans[1] = NULL;
	origin->trans[5] = NULL;
	origin->next = NULL;
	return (origin);
}
