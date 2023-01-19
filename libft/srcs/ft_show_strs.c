/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:10:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/19 22:49:32 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_show_strs(char **strs)
{
	int i;

	i = 0;
	while (strs && strs[i])
	{
		ft_putstr_fd(strs[i], 1);
		ft_putstr_fd("%%\n", 1);
		i++;
	}
}
