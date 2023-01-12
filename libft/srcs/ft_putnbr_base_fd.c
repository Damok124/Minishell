/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:20:38 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 21:51:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	unsigned int	big;

	if (nbr <= (int)(-ft_strlen(base)))
	{
		ft_putchar_fd('-', fd);
		big = nbr * -1;
		ft_putnbr_base_fd(big / ft_strlen(base), base, fd);
		ft_putchar_fd(base[(big % ft_strlen(base))], fd);
	}
	else if (nbr >= 0 && nbr < (int)ft_strlen(base))
		ft_putchar_fd(base[nbr], fd);
	else if (nbr < 0 && nbr > (int)-(ft_strlen(base)))
	{
		ft_putchar_fd('-', fd);
		big = nbr * -1;
		ft_putchar_fd(base[big % ft_strlen(base)], fd);
	}
	else
	{
		ft_putnbr_base_fd(nbr / ft_strlen(base), base, fd);
		ft_putchar_fd(base[(nbr % ft_strlen(base))], fd);
	}
}
