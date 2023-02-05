/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_nod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:02:25 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/05 14:02:25 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_basic_nod(t_nod *nod, char *str, int i)
{
	t_nod	*tmp;

	tmp = nod;
	while (nod && nod->next != NULL)
		nod = nod->next;
	tmp = (t_nod *)malloc(sizeof(t_nod));
	tmp->next = NULL;
	nod->next = tmp;
	tmp->key = ft_substr(str, 0, i);
	tmp->value = ft_substr(str, i + 1, ft_strlen(str));
	tmp->declare = 0;
}

void	ft_add_basic_plus_nod(t_nod *nod, char *str, int i)
{
	t_nod	*tmp;

	while (nod && nod->next != NULL)
		nod = nod->next;
	tmp = (t_nod *)malloc(sizeof(t_nod));
	tmp->next = NULL;
	nod->next = tmp;
	tmp->key = ft_substr(str, 0, i);
	tmp->value = ft_substr(str, i + 2, ft_strlen(str));
	tmp->declare = 0;
}

void	ft_add_mini_nod_basic(t_nod *nod, char *str, int i)
{
	char	*key_str;
	char	*value_str;

	key_str = ft_substr(str, i + 2, ft_strlen(str));
	value_str = ft_strjoin(nod->value, key_str);
	free(nod->value);
	free(key_str);
	nod->value = value_str;
	nod->declare = 0;
}
