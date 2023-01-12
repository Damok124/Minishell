/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:37:34 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/12 15:46:55 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_mini_check_here_doc(t_parsed *lst)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == 'H')
			c++;
		i++;
	}
	return (c);
}

int	ft_check_here_doc(t_parsed *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i += ft_mini_check_here_doc(lst);
		lst = lst->next;
	}
	
	return (i);
}
