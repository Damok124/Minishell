/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_type_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:32:57 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/04 18:51:58 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_perm(char *str)
{
	char	*tmp;

	if (access(str, F_OK) == 0 && (access(str, X_OK) == -1
			|| access(str, R_OK) == -1 || access(str, W_OK) == -1))
	{
		tmp = ft_strjoin(str, ": Permission denied\n");
		ft_putstr_fd(tmp, 2);
		ft_true_free((void **)&tmp);
		return (1);
	}
	return (0);
}

void	ft_print_error_double(char *str, char *str2)
{
	char	*tmp;

	if (!str && !str2)
		return ;
	if (!str && str2)
		ft_putstr_fd(str2, 2);
	if (str && !str2)
		ft_putstr_fd(str, 2);
	if (str && str2)
	{
		tmp = ft_strjoin(str, str2);
		ft_putstr_fd(tmp, 2);
		ft_true_free((void **)&tmp);
	}
}
