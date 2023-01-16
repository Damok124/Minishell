/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:29:03 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/16 17:48:39 by tlarraze         ###   ########.fr       */
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
		i = ft_exit(lst, head, env);
	if (i == 1)
		return (1);
	return (0);
}

int	ft_exit(t_parsed *lst, t_parsed *head, t_nod *env)
{
	int		i;
	int		check;

	check = 1;
	if (lst && lst->cmds && lst->cmds[1])
	{
		i = ft_atoi_safe(lst->cmds[1], &check);
		if (check == 0)
		{
			printf("exit\n");
			printf("Minishell: exit: %s: numeric argument required\n", lst->cmds[1]);
			ft_free_parsed(head);
			ft_free_env(env);
			exit(2);
		}
		while (lst && lst->cmds && lst->cmds[1][i])
		{
			if (ft_isdigit(lst->cmds[1][i]) == 0)
				{
					printf("exit\n");
					printf("Minishell: exit: %s: numeric argument required\n", lst->cmds[1]);
					i = ft_atoi_safe(lst->cmds[1], &check);
					ft_free_parsed(head);
					ft_free_env(env);
					exit(i);
				}
			i++;
		}
	}
	if (lst && lst->cmds && lst->cmds[1] && !lst->cmds[2])
	{
		printf("exit\n");
		i = ft_atoi_safe(lst->cmds[1], &check);
		ft_free_parsed(head);
		ft_free_env(env);
		exit(i);
	}
	if (lst && lst->cmds && lst->cmds[1] && lst->cmds[2])
	{
		printf("exit\nMinishell: exit: too many arguments\n");
		lst = lst->next;
		return (1);
	}
	ft_free_parsed(head);
	ft_free_env(env);
	exit(0);
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