/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_angl_brackets.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:08:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_arg_angl_brackets(char *trans)
{
	int	i;

	i = 0;
	while (trans && trans[i])
	{
		if (ft_strchr("<>", trans[i]))
		{
			while (trans[i] && ft_strchr("<>", trans[i]))
				i++;
			while (trans[i] && trans[i] == ' ')
				i++;
			if (trans[i] && !ft_strchr("$0\'\"", trans[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
