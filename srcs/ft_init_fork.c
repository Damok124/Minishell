/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:08:45 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/20 18:07:28 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_fork(int id, int tmp_stdin)
{
	id = 0;
	id = fork();
	if (id < 0)
		exit(1);
	if (id == 0)
		close(tmp_stdin);
	return (id);
}

void	ft_free_double(char **str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	free(str2);
}
