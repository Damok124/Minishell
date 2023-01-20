/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include_var_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:56:42 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_include_var_env(char **src, char **trans, t_nod *env)
{
	int		i;
	char	*var;

	i = 0;
	var = NULL;
	while (src && src[0] && src[0][i] && trans && trans[0] && trans[0][i])
	{
		if (trans[0][i] == '$')
		{
			var = ft_get_var_env_val(src[0] + i + 1, env);
			ft_replace_with_val(src, trans, var, i);
			i = 0;
		}
		else
			i++;
	}
}
