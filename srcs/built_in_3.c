/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:29:03 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/19 18:34:01 by tlarraze         ###   ########.fr       */
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

int	ft_check_unset_export(t_parsed *lst, t_parsed *head, t_nod *env, int i)
{
	if (i != 0)
		return (0);
	if (lst && lst->cmds && ft_strncmp(lst->cmds[0], "unset", 6) == 0)
		ft_unset(lst->cmds, env);
	if (lst && lst->cmds && ft_strncmp(lst->cmds[0], "export", 6) == 0)
		ft_export(lst->cmds, env, 0);
	if (lst && lst->cmds && strncmp(lst->cmds[0], "exit", 5) == 0)
	{
		ft_exit(lst, head, env);
		i = 1;
	}
	if (lst && lst->cmds && ft_strncmp(lst->cmds[0], "cd", 3) == 0)
		ft_cd(lst->cmds, env, 1);
	if (i == 1)
		return (1);
	return (0);
}

char	**ft_env_to_tab(t_nod *nod)
{
	char	**strs;
	char	*tmp;
	t_nod	*first;
	int		i;

	i = 0;
	first = nod;
	tmp = NULL;
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

void	ft_show_nod(t_nod *nod)
{
	while (nod)
	{
		printf("%s=%s\n", nod->key, nod->value);
		nod = nod->next;
	}
}
