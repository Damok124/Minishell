/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:12:43 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/25 17:13:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_redir(char **srcs, int target, char *set)
{
	char	**strs;
	char	*str;

	strs = ft_split_at_index(srcs[0], target);
	str = ft_begin_strtrim(strs[1], set);
	ft_true_free((void **)&srcs[0]);
	srcs[0] = ft_strjoin(strs[0], str);
	ft_full_free((void **)strs);
	ft_true_free((void **)&str);
}
