/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_free_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:23:40 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/24 18:03:26 by tlarraze         ###   ########.fr       */
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
