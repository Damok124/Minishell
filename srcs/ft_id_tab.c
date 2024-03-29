/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:29:33 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/06 14:19:57 by tlarraze         ###   ########.fr       */
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
		if (status == 131)
		{
			ft_return_value(131, env, (int [1]){0});
			printf("Quit (core dumped)\n");
		}
		else if (status != 2)
		{
			status = WEXITSTATUS(status);
			ft_return_value(status, env, (int [1]){0});
		}
		else
			ft_return_value(130, env, (int [1]){0});
		ft_file_destroy(i);
		i++;
	}
	ft_true_free((void **)&tab);
}
