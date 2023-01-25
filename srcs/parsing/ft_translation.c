/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/25 17:37:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_translation(char **src, char **trans, t_nod *env)
{
	ft_rename_angl_brackets(trans);
	ft_reveal_ambi_redirect(src, trans);
	ft_add_spaces(src, trans);
	ft_disable_var_env(src, trans);
	ft_include_var_env(src, trans, env);
}
