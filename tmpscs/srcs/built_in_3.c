/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:29:03 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/09 14:57:46 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_search_built_in(t_parsed *lst)
{
	if (ft_strncmp(lst->cmds[0], "echo", 5) == 0)
		return (1);
	if (ft_strncmp(lst->cmds[0], "cd", 3) == 0)
		return (2);
	if (ft_strncmp(lst->cmds[0], "pwd", 4) == 0)
		return (3);
	if (ft_strncmp(lst->cmds[0], "export", 7) == 0)
		return (4);
	if (ft_strncmp(lst->cmds[0], "unset", 6) == 0)
		return (5);
	if (ft_strncmp(lst->cmds[0], "env", 4) == 0)
		return (6);
	if (ft_strncmp(lst->cmds[0], "exit", 5) == 0)
		return (7);
	return (0);
}

char **ft_env_to_tab(t_nod *nod)
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
	i = 0;
	while (first)
	{
		tmp = ft_strjoin("=", first->value);
		strs[i] = ft_strjoin(first->key, tmp);
		ft_true_free((void **)&tmp);
		first = first->next;
		i++;
	}
	first = NULL;
	return (strs);
}

void    ft_show_nod(t_nod *nod)
{
    while (nod)
    {
        printf("%s=%s\n", nod->key, nod->value);
        nod = nod->next;
    }
}