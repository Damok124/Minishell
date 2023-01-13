/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:36 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/13 14:59:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_nod *env)
{
	while (env != NULL)
	{
		//if (ft_strncmp(env->key, "$?", 3) != 0)
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
		printf("MAXITMPKEYYYY :%s\n", tmp->key);////////////////////////////
		if (ft_strncmp(str, tmp->key, ft_strlen(str)) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
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
	body->key = ft_strdup("$?");
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

void	ft_export(char **str, t_nod *env)
{
	int		i;
	int		found;
	t_nod	*body;
	t_nod	*tmp;

	i = 1;
	found = 0;
	body = env;
	while (str[i] != NULL)
	{
		while (body->next != NULL)
		{
			body = body->next;
		}
		if (found == 0)
		{
			tmp = ft_init_nod(str[i]);
			tmp->next = NULL;
			body->next = tmp;
		}
		body = env;
		i++;
	}
}
