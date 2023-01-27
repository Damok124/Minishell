/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/27 17:46:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_syntax(char **src, char **trans)
{
	if (!ft_check_format_quotes(trans[0], ft_strlen(trans[0])) \
		|| !ft_check_format_angl_brackets(src[0], trans[0]) \
			|| !ft_check_format_pipes(trans[0]))
	{
		write(2, "minishell : syntax error\n", 25);
		return (0);
	}
	return (1);
}
