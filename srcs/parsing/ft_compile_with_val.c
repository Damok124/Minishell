/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compile_with_val.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:56:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_compile_with_val(char **strs, char *var, int i, int j)
{
	strs[1] = ft_substr(strs[0], 0, i);
	strs[2] = ft_strdup(strs[0] + i + j);
	strs[3] = ft_strjoin(strs[1], var);
	strs[4] = strs[0];
	strs[0] = ft_strjoin(strs[3], strs[2]);
}
