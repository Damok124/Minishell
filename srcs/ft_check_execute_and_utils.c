/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_execute_and_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:19:26 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/04 18:51:11 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_redir(t_parsed *lst[2], t_nod *env, int tmp_stdin, int p1[2])
{
	if (lst[1] && lst[1]->redirections && ft_check_file(lst[1]) == -1)
	{
		ft_return_value(1, env);
		(void)p1;
		(void)tmp_stdin;
		return (1);
	}
	return (0);
}

int	ft_check_exit_null_cmd(t_parsed *lst[2], int tmp_stdin, int p1[2])
{
	if (lst[1]->cmds && ft_strncmp(lst[1]->cmds[0], "exit", 5) == 0
		&& lst[1]->cmds[1] == NULL)
		ft_close(-1, p1[0], p1[1], -1);
	if (lst[1] == NULL)
	{
		ft_clean_end(lst[0], tmp_stdin, p1);
		return (1);
	}
	return (0);
}

int	ft_execute_end(t_parsed *lst[2], int tmp_stdin, int i)
{
	lst[1] = lst[1]->next;
	if (lst[1] == NULL)
		dup2(tmp_stdin, STDIN);
	i++;
	return (i);
}

void	ft_file_destroy(int i)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(i);
	str = ft_strjoin(HEREDOC, tmp);
	unlink(str);
	ft_true_free((void **)&tmp);
	ft_true_free((void **)&str);
}

void	ft_clean_end(t_parsed *lst, int tmp_stdin, int p1[2])
{
	ft_close(tmp_stdin, p1[0], p1[1], -1);
	ft_free_parsed(lst);
}
