/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:21:35 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/02 18:48:38 by tlarraze         ###   ########.fr       */
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
		if (do_it == 0 && check == 0 && ft_strchr(str[i], '=') == NULL)
			ft_add_to_export_no_value(big_nod[0], str[i]);
		else if (do_it == 0 && check == 0 && ft_search_delimiter(str[i]) == 1)
			ft_add_to_env_no_value(big_nod[0], str[i]);
		else if (do_it == 0 && check == 0 && ft_search_delimiter(str[i]) == 0)
			ft_add_basic(big_nod[0], str[i]);
		else if (do_it == 0 && check == 0 && ft_search_delimiter(str[i]) == 2)
			ft_add_basic_and_plus(big_nod[0], str[i]);
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
	while (nod && nod->next != NULL)
		nod = nod->next;
	tmp = (t_nod *)malloc(sizeof(t_nod));
	tmp->next = NULL;
	nod->next = tmp;
	tmp->key = ft_substr(str, 0, i);
	tmp->value = ft_substr(str, i + 1, ft_strlen(str));
	tmp->declare = 0;
	free(key_str);
}

void	ft_add_basic_and_plus(t_nod *nod, char *str)
{
	t_nod	*tmp;
	char	*key_str;
	char	*value_str;
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
			key_str = ft_substr(str, i + 2, ft_strlen(str));
			value_str = ft_strjoin(nod->value, key_str);
			free(nod->value);
			free(key_str);
			nod->value = value_str;
			nod->declare = 0;
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
	tmp->key = ft_substr(str, 0, i);
	tmp->value = ft_substr(str, i + 2, ft_strlen(str));
	tmp->declare = 0;
	free(key_str);
}

void	ft_add_to_env_no_value(t_nod *nod, char *str)
{
	t_nod	*tmp;

	tmp = nod;
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
	tmp->key = ft_strdup(str);
	tmp->value = ft_strdup("");
	tmp->declare = 1;
}

void	ft_add_to_export_no_value(t_nod *nod, char *str)
{
	t_nod	*tmp;

	tmp = nod;
	while (nod)
	{
		if (ft_strncmp(nod->key, str, ft_strlen(nod->key)) == 0)
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
