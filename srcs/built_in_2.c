/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:36 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/23 15:29:56 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_nod *env)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->key, "LEC_RV", 7) != 0)
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}

int	ft_call_built_in(t_parsed *lst, t_parsed *head, t_nod *env, int *id_tab)
{
	int	ret;

	ret = 0;
	if (lst && lst->cmds && ft_search_built_in(lst) == 1)
		ft_echo(lst->cmds);
	if (lst && lst->cmds && ft_search_built_in(lst) == 2)
		ret = ft_cd(lst->cmds, env, 0);
	if (lst && lst->cmds && ft_search_built_in(lst) == 3)
		ft_pwd(lst->cmds);
	if (lst && lst->cmds && ft_search_built_in(lst) == 4)
		ft_export(lst->cmds, env, 1);
	if (lst && lst->cmds && ft_search_built_in(lst) == 5)
		ft_unset(lst->cmds, env);
	if (lst && lst->cmds && ft_search_built_in(lst) == 6)
		ft_env(env);
	if (lst && lst->cmds && ft_search_built_in(lst) == 7)
		ft_exit(lst, head, env, id_tab);
	return (ret);
}

char	*ft_get_env(char *str, t_nod *env)
{
	t_nod	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		if (ft_strncmp(str, tmp->key, ft_strlen(str) + 1) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return ("");
}

t_nod	*ft_init_lst(char **env)
{
	t_nod	*head;
	t_nod	*body;
	t_nod	*tmp;
	int		i;

	i = 0;
	head = ft_init_nod(env[i]);
	tmp = head;
	i++;
	while (env[i] != NULL)
	{
		body = ft_init_nod(env[i]);
		tmp->next = body;
		tmp = tmp->next;
		i++;
	}
	body = (t_nod *)malloc(sizeof(t_nod));
	body->value = ft_strdup("0");
	body->key = ft_strdup("LEC_RV");
	tmp->next = body;
	tmp = tmp->next;
	body->next = NULL;
	return (head);
}

t_nod	*ft_init_nod(char *str)
{
	int		i;
	t_nod	*nod;

	nod = (t_nod *)malloc(sizeof(t_nod));
	i = 0;
	while (str[i] != '=')
		i++;
	str[i] = '\0';
	if (str[i - 1] == '+')
		str[i - 1] = '\0';
	i++;
	nod->value = ft_strdup(str + i);
	nod->key = ft_strdup(str);
	i++;
	return (nod);
}
