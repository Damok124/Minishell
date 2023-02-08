/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:21:35 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/08 21:13:31 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(char **str, t_nod *env, int do_it)
{
	int		i;
	int		check;
	int		error;
	t_nod	*big_nod[3];

	i = 1;
	check = 0;
	error = 0;
	big_nod[0] = env;
	if (!str[1])
		ft_show_declare(env);
	while (str[i])
	{
		if (ft_check_identifier(str[i], 0, do_it) == 1)
		{
			check = 1;
			error = 1;
		}
		ft_choose_export(big_nod, do_it, check, str[i]);
		check = 0;
		big_nod[0] = env;
		i++;
	}
	return (error);
}

void	ft_add_basic(t_nod *nod, char *str)
{
	t_nod	*tmp;
	char	*key_str;
	int		i;

	tmp = nod;
	i = 0;
	while (str[i] != '=')
		i++;
	key_str = ft_substr(str, 0, i);
	while (nod)
	{
		if (ft_strncmp(nod->key, key_str, ft_strlen(nod->key) + 1) == 0)
		{
			free(nod->value);
			nod->value = ft_substr(str, i + 1, ft_strlen(str));
			nod->declare = 0;
			free(key_str);
			return ;
		}
		nod = nod->next;
	}
	nod = tmp;
	ft_add_basic_nod(nod, str, i);
	ft_true_free((void **)&key_str);
}

void	ft_add_basic_and_plus(t_nod *nod, char *str)
{
	t_nod	*tmp;
	char	*key_str;
	int		i;

	tmp = nod;
	i = 0;
	while (str[i] != '=')
		i++;
	i--;
	key_str = ft_substr(str, 0, i);
	while (nod)
	{
		if (ft_strncmp(nod->key, key_str, ft_strlen(nod->key) + 1) == 0)
		{
			free(key_str);
			ft_add_mini_nod_basic(nod, str, i);
			return ;
		}
		nod = nod->next;
	}
	nod = tmp;
	ft_add_basic_plus_nod(nod, str, i);
	ft_true_free((void **)&key_str);
}

void	ft_add_to_env_no_value(t_nod *nod, char *str)
{
	t_nod	*tmp;

	tmp = nod;
	str = ft_cut_plus(str);
	while (nod)
	{
		if (ft_strncmp(nod->key, str, ft_strlen(nod->key) + 1) == 0)
		{
			free(nod->value);
			nod->value = ft_strdup("");
			nod->declare = 1;
			return ;
		}
		nod = nod->next;
	}
	nod = tmp;
	while (nod && nod->next != NULL)
		nod = nod->next;
	tmp = (t_nod *)malloc(sizeof(t_nod));
	tmp->next = NULL;
	nod->next = tmp;
	tmp->key = ft_strdup(ft_check_plus_key(str));
	tmp->value = ft_strdup("");
	tmp->declare = 1;
}

void	ft_add_to_export_no_value(t_nod *nod, char *str)
{
	t_nod	*tmp;

	tmp = nod;
	while (nod)
	{
		if (ft_strncmp(nod->key, str, ft_strlen(nod->key) + 1) == 0)
			return ;
		nod = nod->next;
	}
	nod = tmp;
	while (nod && nod->next != NULL)
		nod = nod->next;
	tmp = (t_nod *)malloc(sizeof(t_nod));
	tmp->next = NULL;
	nod->next = tmp;
	tmp->key = ft_strdup(str);
	tmp->value = NULL;
	tmp->declare = 2;
}
