/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:42:47 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/27 08:04:24 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_pn(unsigned long nbr, char *b, unsigned long len, int *ptr)
{
	if (nbr < len)
		ft_countnprintf(b[nbr], ptr);
	else
	{
		ft_u_pn(nbr / len, b, len, ptr);
		ft_countnprintf(b[nbr % len], ptr);
	}
}

void	ft_pnbrprintf(int nbr, char *b, int len, int *ptr)
{
	unsigned int	big;

	if (nbr <= -len)
	{
		ft_countnprintf('-', ptr);
		big = nbr * -1;
		ft_pnbrprintf(big / len, b, len, ptr);
		ft_countnprintf(b[big % len], ptr);
	}
	else if (nbr >= 0 && nbr < len)
		ft_countnprintf(b[nbr], ptr);
	else if (nbr < 0 && nbr > -len)
	{
		ft_countnprintf('-', ptr);
		big = nbr * -1;
		ft_countnprintf(b[big % len], ptr);
	}
	else
	{
		ft_pnbrprintf(nbr / len, b, len, ptr);
		ft_countnprintf(b[nbr % len], ptr);
	}
}

void	ft_parsenprintf2(const char *s, int *i, va_list *vlist, int *ptr)
{
	if (s[*i] && s[*i] == 'x')
		ft_u_pn(va_arg(*vlist, unsigned int), "0123456789abcdef", 16, ptr);
	else if (s[*i] && s[*i] == 'X')
		ft_u_pn(va_arg(*vlist, unsigned int), "0123456789ABCDEF", 16, ptr);
	else if (s[*i] == '%')
		ft_countnprintf('%', ptr);
}

void	ft_parsenprintf1(const char *s, int *i, va_list *vlist, int *ptr)
{
	va_list	vcopy;

	if (s[*i] == 'c')
		ft_countnprintf(va_arg(*vlist, int), ptr);
	else if (s[*i] == 's')
		ft_strprintf(va_arg(*vlist, char *), ptr);
	else if (s[*i] == 'p')
	{
		va_copy(vcopy, *vlist);
		if (va_arg(vcopy, unsigned long int) == 0)
			ft_strprintf("(nil)", ptr);
		else
		{
			ft_strprintf("0x", ptr);
			ft_u_pn(va_arg(*vlist, unsigned long), "0123456789abcdef", 16, ptr);
		}
		va_copy(*vlist, vcopy);
		va_end(vcopy);
	}
	else if (s[*i] == 'd' || s[*i] == 'i' )
		ft_pnbrprintf(va_arg(*vlist, int), "0123456789", 10, ptr);
	else if (s[*i] && s[*i] == 'u')
		ft_u_pn(va_arg(*vlist, unsigned int), "0123456789", 10, ptr);
	else
		ft_parsenprintf2(s, i, vlist, ptr);
}

int	ft_printf(const char *s, ...)
{
	va_list	vlist;
	int		total;
	int		*ptr;
	int		*i;
	int		j;

	total = 0;
	j = -1;
	ptr = &total;
	i = &j;
	va_start(vlist, s);
	while (s[++j])
	{
		if (s[j] != '%')
			ft_countnprintf(s[j], ptr);
		else
		{
			j++;
			if (s[j])
				ft_parsenprintf1(s, i, &vlist, ptr);
		}
	}
	va_end(vlist);
	return (total);
}
