/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_with_val.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:56:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_with_val(char **src, char **trans, char *var, int i)
{
	char	*tmp;
	int		j;
	int		k;

	j = 1;
	k = -1;
	tmp = NULL;
	if (src && src[0] && trans && trans[0] && var)
	{
		while (src[0][i] && src[0][i + j] && ft_isalnum(src[0][i + j]))
			j++;
		if (j == 1 && src[0][i] && src[0][i + j] == '?')
			j = 2;
		ft_compile_with_val(src, var, i, j);
		tmp = ft_strdup(var);
		while (tmp[++k])
			tmp[k] = '0';
		ft_compile_with_val(trans, tmp, i, j);
		ft_true_free((void **)&tmp);
		ft_only_strs_free(src + 1);
		ft_only_strs_free(trans + 1);
	}
}
