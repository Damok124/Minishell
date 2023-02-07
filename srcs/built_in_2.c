/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:36 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/07 14:32:03 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_nod *env)
{
	while (env != NULL)
	{
		if (env->declare == 0)
			printf("%s=%s\n", env->key, env->value);
		if (env->declare == 1)
			printf("%s%s\n", env->key, env->value);
		env = env->next;
	}
}

int	ft_call_built_in(t_core *core, t_nod *env, int *id_tab)
{
	int	ret;

	ret = 0;
	if (core->lst[1]->cmds && ft_search_built_in(core->lst[1]) == 1)
		ft_echo(core->lst[1]->cmds);
	if (core->lst[1]->cmds && ft_search_built_in(core->lst[1]) == 2)
		ret = ft_cd(core->lst[1]->cmds, env, 0);
	if (core->lst[1]->cmds && ft_search_built_in(core->lst[1]) == 3)
		ft_pwd(core->lst[1]->cmds);
	if (core->lst[1]->cmds && ft_search_built_in(core->lst[1]) == 4)
		ret = ft_export(core->lst[1]->cmds, env, 0);
	if (core->lst[1]->cmds && ft_search_built_in(core->lst[1]) == 5)
		ft_unset(core->lst[1]->cmds, env, 0);
	if (core->lst[1]->cmds && ft_search_built_in(core->lst[1]) == 6)
		ft_env(env);
	if (core->lst[1]->cmds && ft_search_built_in(core->lst[1]) == 7)
		ft_exit(core, 1, env, id_tab);
	return (ret);
}

char	*ft_get_env(char *str, t_nod *env)
{
	while (env != NULL)
	{
		if (ft_strncmp(str, env->key, ft_strlen(str) + 1) == 0)
			return (env->value);
		env = env->next;
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
	body->declare = 5;
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
	nod->declare = 0;
	i++;
	return (nod);
}
