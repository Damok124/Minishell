/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:10:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:37:36 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_show_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		ft_putstr_fd(strs[i], 1);
		ft_putstr_fd("%%\n", 1);
		i++;
	}
}
