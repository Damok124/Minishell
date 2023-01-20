/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_var_env_val.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:55:42 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_var_env_val(char *src, t_nod *env)
{
	char	*copy;
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	copy = NULL;
	if (src)
	{
		if (src[i] && src[i] == '?')
			copy = ft_strdup("LEC_RV");
		else
		{
			while (src[i] && ft_isalnum(src[i]))
				i++;
			copy = ft_substr(src, 0, i);
		}
		ret = ft_get_env(copy, env);
		ft_true_free((void **)&copy);
		if (ret)
			return (ret);
	}
	return ("");
}
