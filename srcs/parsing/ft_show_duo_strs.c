/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_duo_strs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:06:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_show_duo_strs(char **strs1, char **strs2)
{
	int	i;

	i = 0;
	printf(">src   :");
	while (strs1 && strs1[i])
	{
		printf("%s", strs1[i]);
		printf("%%");
		i++;
	}
	i = 0;
	printf("\n");
	printf(">trans :");
	while (strs2 && strs2[i])
	{
		printf("%s", strs2[i]);
		printf("%%");
		i++;
	}
	printf("\n");
}
