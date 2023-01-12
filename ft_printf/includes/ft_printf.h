/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:38:21 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/02 17:37:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_parsenprintf1(const char *s, int *i, va_list *vlist, int *ptr);
void	ft_parsenprintf2(const char *s, int *i, va_list *vlist, int *ptr);
void	ft_pnbrprintf(int nbr, char *b, int len, int *ptr);
void	ft_u_pn(unsigned long nbr, char *b, unsigned long len, int *ptr);
void	ft_strprintf(char *str, int *ptr);
void	ft_countnprintf(char c, int *ptr);
void	ft_print_strs(char **strs);

#endif
