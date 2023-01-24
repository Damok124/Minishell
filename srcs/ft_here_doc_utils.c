/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:01:33 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/24 18:05:51 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_here_doc_or_infile(t_parsed *lst)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == 'H')
			c++;
		if (lst->redirections[i][0] == '<')
			c++;
		i++;
	}
	return (c);
}

void	ft_exit_here_doc_status(t_parsed *lst, int i, t_nod *env)
{
	int	res;

	res = ft_create_here_doc(lst, env, i);
	ft_free_parsed(lst);
	ft_free_env(env);
	if (res == -1)
		exit (-1);
	exit(0);
}
