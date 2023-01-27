/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:21:35 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/27 18:50:51 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(char **str, t_nod *env, int do_it)
{
	int		i;
	int		found;
	t_nod	*big_nod[3];

	big_nod[0] = env;
	i = 1;
	found = 0;
	big_nod[1] = big_nod[0];
	if (ft_check_export_identifier(str) == 1 || ft_minus_before(str) == 1)
		return (1);
	if (str[1] != NULL && do_it == 1)
		return (0);
	if (!str[1])
		ft_show_declare(big_nod[0]);
	while (str[i] != NULL && big_nod[1]->next != NULL)
	{
		if (ft_strrchr(str[i], '=') == NULL)
			return (0);
		found = ft_exporting(big_nod, str, found, i);
		if (ft_make_nod(big_nod, str, i, found) == 1)
			return (0);
		found = 0;
		i++;
	}
	ft_add_declare(big_nod, str);
	return (0);
}

int	ft_check_export_identifier(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strchr(str[i], '=') == NULL && ft_strchr(str[i], '-') != NULL)
		{
			ft_putstr_fd("Minishell: export: not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	i = 0;
	return (0);
}

int	ft_exporting(t_nod *big_nod[3], char **str, int found, int i)
{
	while (big_nod[1]->next != NULL)
	{
		if (ft_fuse_export(big_nod[1], str[i]) == 1)
			found = 1;
		big_nod[1] = big_nod[1]->next;
		if (big_nod[1]->next == NULL)
			if (ft_fuse_export(big_nod[1], str[i]) == 1)
				found = 1;
	}
	if (found == 1)
		return (1);
	return (0);
}

int	ft_fuse_export(t_nod *nod, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (str[i - 1] == '+' && strncmp(nod->key, str, ft_strlen(nod->key)) == 0)
	{
		tmp = nod->value;
		nod->value = ft_strjoin(nod->value, str + i + 1);
		ft_true_free((void **)&tmp);
		return (1);
	}
	else if ((strncmp(nod->key, str, ft_strlen(nod->key)) == 0))
	{
		ft_true_free((void **)&nod->value);
		nod->value = ft_strdup(str + i + 1);
		return (1);
	}
	return (0);
}

void	ft_show_declare(t_nod *env)
{
	while (env != NULL)
	{
		if (env->declare == 0)
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
		if (env->value != NULL)
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
		else 
			printf("declare -x %s\n", env->key);
		env = env->next;
	}
}
