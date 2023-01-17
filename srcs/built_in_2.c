/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:36 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/17 16:53:43 by tlarraze         ###   ########.fr       */
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
	i++;
	nod->value = ft_strdup(str + i);
	nod->key = ft_strdup(str);
	i++;
	return (nod);
}

void	ft_export(char **str, t_nod *env, int doo)
{
	int		i;
	int		found;
	t_nod	*body;
	t_nod	*tmp;

	i = 1;
	found = 0;
	body = env;
	if (str[1] != NULL && doo == 1)
		return ;
	while (str[i] != NULL && body->next != NULL)
	{
		if (ft_strchr(str[i], '=') == NULL)
			return ;
		while (body->next != NULL)
		{
			if (!str[1])
				printf("declare -x %s=\"%s\"\n", body->key,body->value);
			body = body->next;
		}
		if (str[1] == NULL)
			return ;
		if (found == 0 && str[1] != NULL)
		{
			tmp = ft_init_nod(str[i]);
			tmp->next = NULL;
			body->next = tmp;
		}
		body = env;
		i++;
	}
}
