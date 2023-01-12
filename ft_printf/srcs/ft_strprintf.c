/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:55:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/05/26 19:06:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strprintf(char *str, int *ptr)
{
	int		n;

	n = -1;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*ptr += 6;
	}
	else if (str)
	{
		while (str[++n])
			ft_countnprintf(str[n], ptr);
	}
}
