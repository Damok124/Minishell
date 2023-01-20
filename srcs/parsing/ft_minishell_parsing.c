/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:04:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parsed	*ft_minishell_parsing(char *str1, t_nod *env)
{
	t_parsed	*final;
	t_twins		*origin;
	t_twins		*lst;

	final = NULL;
	origin = ft_init_origin(NULL, str1);
	lst = NULL;
	ft_label_src_into_trans(origin->src, origin->trans);
	if (origin->trans && origin->trans[0] && origin->trans[0][0] \
		&& ft_check_syntax(origin->src, origin->trans))
	{
		ft_translation(origin->src, origin->trans, env);
		ft_split_on_pipes(origin);
		lst = ft_init_lst_twins((int)ft_strslen(origin->trans));
		final = ft_init_lst_parsed((int)ft_strslen(origin->trans));
		ft_split_on_spaces(lst, origin->src, origin->trans);
		ft_lst_clean_quotes(lst);
		ft_lst_clean_redirections(lst);
		ft_lst_to_final(lst, final);
	}
	ft_free_twins(origin);
	ft_free_twins(lst);
	return (final);
}
