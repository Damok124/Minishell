/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:29:33 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/04 17:30:55 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*ft_make_id_tab(t_parsed *lst)
{
	int	i;
	int	*tab;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	tab = (int *)calloc(i + 1, sizeof(int));
	tab[i] = '\0';
	i = 0;
	while (tab[i] != '\0')
	{
		tab[i] = -666;
		i++;
	}
	return (tab);
}

void	ft_wait_id(t_nod *env, int *tab)
{
	int	i;
	int	status;

	i = 0;
	while (tab[i] != '\0' && tab[i] != -666)
	{
		waitpid(tab[i], &status, 0);
		status = WEXITSTATUS(status);
		ft_return_value(status, env);
		ft_file_destroy(i);
		i++;
	}
	ft_true_free((void **)&tab);
}
