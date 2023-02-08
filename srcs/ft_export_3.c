/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:13:17 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/08 21:14:59 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_cut_plus(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '+' && str[i] != '=')
		i++;
	str[i] = '\0';
	return (str);
}

char	*ft_check_plus_key(char *str)
{
	int	i;

	i = 0;
	if (ft_strchr(str, '+') == NULL)
		return (str);
	while (str[i] != '+' && str[i] != '\0')
		i++;
	str[i] = '\0';
	return (str);
}
