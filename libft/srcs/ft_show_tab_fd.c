/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:25:42 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 22:01:13 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_show_tab_fd(int len, int *tab, int fd)
{
	int	i;

	i = 0;
	while (tab && i < len)
	{
		write(fd, "[", 1);
		ft_putnbr_fd(tab[i], fd);
		write(fd, "]", 1);
		i++;
	}
	if (i)
		write(fd, "\n", 1);
}
