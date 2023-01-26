/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_pipex_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:22:44 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/26 15:42:02 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_pipex_2(t_parsed *lst[2], t_nod *env, char **tab, char *path)
{
	if (path && lst && lst[1] && lst[1]->cmds
		&& lst[1]->cmds[0] && path != lst[1]->cmds[0])
		ft_free_double(tab, path);
	else
		ft_full_free((void **)tab);
	ft_free_env(env);
	ft_free_parsed(lst[0]);
	(void)path;
	(void)tab;
}

int	*ft_init_execute(t_parsed *lst, int *i, int *fd)
{
	int	*id_tab;

	*i = 0;
	*fd = dup(STDIN);
	id_tab = ft_make_id_tab(lst);
	return (id_tab);
}
