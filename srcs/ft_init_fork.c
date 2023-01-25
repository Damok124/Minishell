/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:08:45 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/24 19:22:01 by tlarraze         ###   ########.fr       */
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
		ft_close(tmp_stdin, -1, -1, -1);
	return (id);
}

int	ft_check(t_parsed *lst[2], t_nod *env, int tmp_stdin, int p1[2])
{
	if (ft_check_redir(lst, env, tmp_stdin, p1) == 1)
		return (1);
	if (ft_check_exit_null_cmd(lst, tmp_stdin, p1) == 1)
		return (1);
	ft_pipe(p1, lst);
	return (0);
}

void	ft_pipe(int p1[2], t_parsed *lst[2])
{
	if (ft_search_built_in(lst[1]) == 7)
	{
		p1[0] = -1;
		p1[1] = -1;
		return ;
	}
	if (pipe(p1) == -1)
		exit(-1);
	(void)lst;
}

void	ft_free_double(char **str, char *str2)
{
	int	i;

	i = 0;
	ft_full_free((void **)str);
	ft_true_free((void **)&str2);
	(void)str2;
}