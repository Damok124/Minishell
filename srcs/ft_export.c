/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:21:35 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/18 18:00:40 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(char **str, t_nod *env, int do_it)
{
	int		i;
	int		found;
	t_nod	*body;
	t_nod	*tmp;

	i = 1;
	found = 0;
	body = env;
	if (str[1] != NULL && do_it == 1)
		return ;
	if (!str[1])
		ft_show_declare(env);
	while (str[i] != NULL && body->next != NULL)
	{
		if (ft_strchr(str[i], '=') == NULL)
			return ;
		while (body->next != NULL)
		{
			if (ft_fuse_export(body, str[i]) == 1)
				found = 1;
			body = body->next;
			if (body->next == NULL)
				if (ft_fuse_export(body, str[i]) == 1)
					found = 1;		}
		if (str[1] == NULL)
			return ;
		if (found == 0)
		{
			tmp = ft_init_nod(str[i]);
			tmp->next = NULL;
			body->next = tmp;
		}
		found = 0;
		body = env;
		i++;
	}
}

int	ft_fuse_export(t_nod *nod, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i - 1] == '+' && strncmp(nod->key, str, ft_strlen(nod->key)) == 0)
	{
		tmp = nod->value;
		nod->value = ft_strjoin(nod->value, str + i + 1);
		free(tmp);
		return (1);
	}
	else if ((strncmp(nod->key, str, ft_strlen(nod->key)) == 0))
	{
		free(nod->value);
		nod->value = ft_strdup(str + i + 1);
		return (1);
	}
	return (0);
}

void	ft_show_declare(t_nod *env)
{
	while (env != NULL)
	{
		printf("declare -x %s=\"%s\"\n", env->key, env->value);
		env = env->next;		
	}
}