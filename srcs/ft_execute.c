/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:01:46 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/23 19:47:41 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ft_show_lst_parsed(lst[0]);
#include "minishell.h"

extern int	g_child_id;

void	ft_execute(char *str, t_nod *env)
{
	t_parsed	*lst[2];
	int			p1[3];
	int			i;

	lst[0] = ft_minishell_parsing(ft_strdup(str), env);
	lst[1] = lst[0];
	p1[0] = -1;
	p1[1] = -1;
	i = ft_here_doc(lst[1], env);
	if (ft_error_heredoc(lst[1], env, &i) != 0)
		return ;
	i = 0;
	ft_execute_core(lst, env, p1, str);
}

void	ft_execute_core(t_parsed *lst[2], t_nod *env, int p1[2], char *str)
{
	int	i;
	int	tmp_stdin;
	int	*id_tab;
	int	id;

	i = 0;
	tmp_stdin = dup(STDIN);
	id_tab = ft_make_id_tab(lst[1]);
	while (lst[1])
	{
		if (ft_check(lst, env, tmp_stdin, p1) == 1)
			return ;
		if (ft_check_unset_export(lst, id_tab, env, i) == 1 && i == 0)
			return ;
		id_tab[i] = ft_init_fork(id_tab[i], tmp_stdin);
		id = id_tab[i];
		ft_init_pipe(lst[1], p1, id_tab[i], i);
		if (str != NULL && id == 0)
			ft_execute_cmd(lst, env, id_tab, p1);
		ft_execute_end(lst, tmp_stdin);
		ft_file_destroy(i);
		i++;
	}
	ft_wait_id(env, id_tab);
	ft_clean_end(lst[0], tmp_stdin, p1);
}

void	ft_init_pipe(t_parsed *lst, int p1[2], int id, int i)
{
	int	j;

	j = 0;
	j = ft_do_need_pipe(lst, j);
	lst->empty = i;
	if (id == 0)
	{
		if (lst != NULL && lst->next != NULL)
			ft_clean_connect(STDOUT, p1[1], p1[0]);
		else
			ft_close(p1[1], -1, -1, -1);
	}
	if (id != 0)
		ft_clean_connect(STDIN, p1[0], p1[1]);
	else
		ft_close(p1[0], -1, -1, -1);
	if (j == 3)
	{
		ft_close(p1[1], p1[0], -1, -1);
		return ;
	}
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
