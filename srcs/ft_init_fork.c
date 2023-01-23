/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:08:45 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/23 18:03:48 by tlarraze         ###   ########.fr       */
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

int	ft_check(t_parsed *lst[2], t_nod *env, int tmp_stdin, int p1[2])
{
	if (ft_check_redir(lst, env, tmp_stdin, p1) == 1)
		return (1);
	if (ft_check_exit_null_cmd(lst, tmp_stdin, p1) == 1)
		return (1);
	if (lst && lst[1]->cmds && strncmp(lst[1]->cmds[0], "exit", 5) == 0)
		close(tmp_stdin);
	ft_pipe(p1, lst);
	return (0);
}

void	ft_pipe(int p1[2], t_parsed *lst[2])
{
	if (ft_search_built_in(lst[1]) == 7)
		return ;
	if (pipe(p1) == -1)
		exit(-1);
}

void	ft_free_double(char **str, char *str2)
{
	int	i;

	i = 0;
	while (str != NULL && str[i])
	{
		free(str[i]);
		i++;
	}
	if (str != NULL)
	{
		free(str[i]);
		free(str);
	}
	if (str2 != NULL)
		free(str2);
}
