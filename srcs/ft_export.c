/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:21:35 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/26 18:46:06 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(char **str, t_nod *env, int do_it)
{
	int		i;
	int		found;
	t_nod	*big_nod[3];

	big_nod[0] = env;
	i = 1;
	found = 0;
	big_nod[1] = big_nod[0];
	if (str[1] != NULL && do_it == 1)
		return ;
	if (!str[1])
		ft_show_declare(big_nod[0]);
	while (str[i] != NULL && big_nod[1]->next != NULL)
	{
		if (ft_strchr(str[i], '=') == NULL)
			return ;
		found = ft_exporting(big_nod, str, found, i);
		if (ft_make_nod(big_nod, str, i, found) == 1)
			return ;
		found = 0;
		i++;
	}
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

int	ft_make_nod(t_nod *big_nod[3], char **str, int i, int found)
{
	if (str[1] == NULL)
		return (1);
	if (found == 0)
	{
		big_nod[2] = ft_init_nod(str[i]);
		big_nod[2]->next = NULL;
		big_nod[1]->next = big_nod[2];
	}
	big_nod[1] = big_nod[0];
	i++;
	return (0);
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
	if (str[i - 1] == '-')
		ft_putstr_fd("Minishell : export: '-': not a valid identifier", 1);
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
		printf("declare -x %s=\"%s\"\n", env->key, env->value);
		env = env->next;
	}
}
