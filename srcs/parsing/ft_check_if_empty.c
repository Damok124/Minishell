/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_empty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:02:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_if_empty(t_parsed *final)
{
	int	test;
	int	i;

	i = 0;
	test = 0;
	if (final->cmds || final->redirections)
	{
		while (final->cmds && final->cmds[i])
		{
			if (final->cmds[i][0])
				test++;
			i++;
		}
		i = 0;
		while (final->redirections && final->redirections[i])
		{
			if (final->redirections[i][1])
				test++;
			i++;
		}
	}
	if (!test)
		return (1);
	return (0);
}
