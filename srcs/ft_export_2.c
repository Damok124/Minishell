/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:32:06 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/02 18:16:35 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_search_delimiter(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (3);
	if (str[i + 1] == '\0')
		return (1);
	if (str[i - 1] == '+')
		return (2);
	return (0);
}

void	ft_show_declare(t_nod *env)
{
	while (env != NULL)
	{
		if (env->declare == 0)
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
		if (env->declare == 1)
			printf("declare -x %s\"%s\"\n", env->key, env->value);
		if (env->declare == 2)
			printf("declare -x %s\n", env->key);
		if (env->declare == 4)
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
		env = env->next;
	}
}

int	ft_check_first_export(char **str, int i)
{
	if (str[i][0] == '+' || str[i][0] == '-' || str[i][0] == '=')
		return (1);
	return (0);
}

void	ft_add_declare(t_nod *nod[3], char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		while (nod[1]->next != NULL)
			nod[1] = nod[1]->next;
		if (ft_strchr(str[i], '=') != NULL)
		{
			ft_make_nod(nod, str, i, 0);
			nod[2]->declare = 1;
		}
		nod[1] = nod[0];
		i++;
	}
}

int	ft_call_export(t_parsed *lst[2], t_nod *env, int i)
{
	if (lst && lst[1]->cmds && ft_strncmp(lst[1]->cmds[0], "export", 6) == 0)
	{
		ft_return_value(ft_export(lst[1]->cmds, env, 0), env);
	}
	return (i);
}
