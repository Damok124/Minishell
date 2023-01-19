/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:01:46 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/19 17:24:54 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_child_id;

int	ft_execute(char *str, t_nod *env)
{
	t_parsed	*lst[2];
	int			p1[2];
	int			id;
	int			i;
	int			tmp_stdin;

	lst[0] = ft_minishell_parsing(ft_strdup(str), env);
	//ft_show_lst_parsed(lst[0]);
	lst[1] = lst[0];
	tmp_stdin = dup(STDIN);
	p1[0] = -1;
	p1[1] = -1;
	i = ft_here_doc(lst[1], env);
	if (i != 0)
	{
		ft_free_parsed(lst[0]);
		if (i == -1)
		{
			ft_return_value(0, env);
			return (0);
		}
		else
		{
			ft_return_value(130, env);
			return (130);
		}
	}
	i = 0;
	while (lst[1])
	{
		while (lst[1] && lst[1]->redirections && ft_check_file(lst[1]) == -1)
		{
			lst[1] = lst[1]->next;
			if (!lst[1])
			{
				ft_return_value(1, env);
				return (ft_clean_end(lst[0], tmp_stdin, p1));
			}
		}
		if (pipe(p1) == -1)
			exit(-1);
		if (lst[1]->cmds && ft_strncmp(lst[1]->cmds[0], "exit", 5) == 0
			&& lst[1]->cmds[1] == NULL)
			ft_close(tmp_stdin, p1[0], p1[1], -1);
		if (ft_check_unset_export(lst[1], lst[0], env, i) == 1 && i == 0)
			lst[1] = lst[1]->next;
		if (lst[1] == NULL)
			return (ft_clean_end(lst[0], tmp_stdin, p1));
		id = fork();
		if (id == -1)
			exit(1);
		if (id == 0)
			close(tmp_stdin);
		ft_init_pipe(lst[1], p1, id);
		if (str != NULL && id == 0)
			ft_pipex(lst, env, i, p1);
		if (id != 0)
			waitpid(id, &id, 0);
		id = WEXITSTATUS(id);
		ft_return_value(id, env);
		lst[1] = lst[1]->next;
		ft_file_destroy(str, i);
		i++;
		if (lst[1] == NULL)
			dup2(tmp_stdin, STDIN);
	}
	ft_clean_end(lst[0], tmp_stdin, p1);
	return (id);
}

int	ft_clean_end(t_parsed *lst, int tmp_stdin, int p1[2])
{
	ft_close(tmp_stdin, p1[0], p1[1], -1);
	ft_free_parsed(lst);
	return (0);
}

void	ft_file_destroy(char *str, int i)
{
	char	*tmp;

	tmp = ft_itoa(i);
	str = ft_strjoin(HEREDOC, tmp);
	unlink(str);
	free(tmp);
	free(str);
}

void	ft_init_pipe(t_parsed *lst, int p1[2], int id)
{
	int	j;

	j = 0;
	j = ft_do_need_pipe(lst, j);
	if (j == 3)
		return ;
	if (id == 0)
	{
		if (lst != NULL && lst->next != NULL)
			ft_clean_connect(STDOUT, p1[1], p1[0]);
		else
			close(p1[1]);
	}
	if (id != 0)
		ft_clean_connect(STDIN, p1[0], p1[1]);
	else
		close(p1[0]);
}

int	ft_do_need_pipe(t_parsed *lst, int j)
{
	if (ft_check_outfile(lst) != 0)
		j++;
	if (ft_check_here_doc_or_infile(lst) != 0)
	{
		if (j == 1)
			j = 3;
		else
			j = 2;
	}
	return (j);
}

void	ft_close(int a, int b, int c, int d)
{
	if (a >= 0)
		close(a);
	if (b >= 0)
		close(b);
	if (c >= 0)
		close(c);
	if (d >= 0)
		close(d);
}
