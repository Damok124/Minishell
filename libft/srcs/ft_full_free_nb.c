/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_free_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:23:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/28 14:12:42 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_full_free_nb(void **tobefreed, int nb)
{
	int	i;

	i = -1;
	while (tobefreed && ++i < nb)
	{
		if (tobefreed[i])
			ft_true_free(&tobefreed[i]);
	}
	free(tobefreed);
	tobefreed = NULL;
}
