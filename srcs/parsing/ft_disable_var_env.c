/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disable_var_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/04 20:11:34 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_disable_var_env(char **src, char **trans)
{
	char	*tmp;
	int		heredocs;
	int		i;
	int		len;

	i = 0;
	tmp = NULL;
	len = ft_strlen(trans[0]);
	heredocs = ft_occurences_counter(trans[0], "H0");
	while (trans && (len - i) >= 3 && heredocs)
	{
		tmp = ft_strnstr(trans[0] + i, "H0", 2);
		if (tmp)
		{
			tmp = NULL;
			heredocs -= 1;
			if (ft_strnstr(trans[0] + i + 2, "$", len - (i + 2)))
				ft_remove_symbol_var_env(src, trans, i + 2);
			i++;
		}
		i++;
	}
	ft_disable_unnamed_var_env(trans);
	ft_disable_no_name_var_env(trans);
}
