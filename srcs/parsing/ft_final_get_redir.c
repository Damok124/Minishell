/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_get_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:02:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_final_get_redir(char **redir, char **src, char **trans)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (src && trans && src[i] && trans[i])
	{
		if (ft_isredirection(trans[i]))
		{
			tmp = ft_strtrim(src[i], "\a\b\t\n\v\f\r ");
			redir[j] = ft_strjoin(trans[i], tmp);
			j++;
			if (tmp)
				ft_true_free((void **)&tmp);
		}
		i++;
	}
}
