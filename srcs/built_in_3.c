/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:29:03 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/06 14:08:13 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_search_built_in(t_parsed *lst)
{
	if (lst && lst->cmds && ft_strncmp(lst->cmds[0], "echo", 5) == 0)
		return (1);
	if (lst && lst->cmds && ft_strncmp(lst->cmds[0], "cd", 3) == 0)
		return (2);
	if (lst && lst->cmds && ft_strncmp(lst->cmds[0], "pwd", 4) == 0)
		return (3);
	if (lst && lst->cmds && ft_strncmp(lst->cmds[0], "export", 7) == 0)
		return (4);
	if (lst && lst->cmds && ft_strncmp(lst->cmds[0], "unset", 6) == 0)
		return (5);
	if (lst && lst->cmds && ft_strncmp(lst->cmds[0], "env", 4) == 0)
		return (6);
	if (lst && lst->cmds && ft_strncmp(lst->cmds[0], "exit", 5) == 0)
		return (7);
	return (0);
}

int	ft_check_unset_export(t_core *core, t_nod *env, int i)
{
	if (i > 0 || core->lst[0]->next != NULL)
		return (0);
	i = 0;
	if (core->lst[1]->cmds && ft_strncmp(core->lst[1]->cmds[0]
			, "unset", 6) == 0)
		ft_return_value(ft_unset(core->lst[1]->cmds, env, 0), env, &i);
	i = ft_call_export(core->lst, env, i);
	if (core->lst[1]->cmds && strncmp(core->lst[1]->cmds[0], "exit", 5) == 0)
		ft_return_value(ft_exit(core, 0, core->env, core->id_tab), env, &i);
	if (core->lst[1]->cmds && ft_strncmp(core->lst[1]->cmds[0], "cd", 3) == 0)
		ft_return_value(ft_cd(core->lst[1]->cmds, env, 0), env, &i);
	if (i == 1)
		core->lst[1] = core->lst[1]->next;
	if (core->lst[1] == NULL)
	{
		ft_close(core->p1[0], core->p1[1], -1, -1);
		ft_free_parsed(core->lst[0]);
		ft_true_free((void **)&core->id_tab);
		return (1);
	}
	return (0);
}

char	**ft_env_to_tab(t_nod *nod, t_parsed *lst[2])
{
	char	**strs;
	char	*tmp;
	t_nod	*first;
	int		i;

	i = 0;
	first = nod;
	tmp = NULL;
	if (ft_search_built_in(lst[1]) == 7)
		return (NULL);
	while (nod)
	{
		i++;
		nod = nod->next;
	}
	strs = (char **)malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	strs[i] = NULL;
	ft_fuse_end_env(first, strs);
	first = NULL;
	return (strs);
}

void	ft_fuse_end_env(t_nod *first, char **strs)
{
	int		i;
	char	*tmp;

	i = 0;
	while (first != NULL)
	{
		tmp = ft_strjoin("=", first->value);
		strs[i] = ft_strjoin(first->key, tmp);
		ft_true_free((void **)&tmp);
		first = first->next;
		i++;
	}
}
