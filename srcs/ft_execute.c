/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:01:46 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/06 18:17:54 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_child_id;

void	ft_execute(char *str, t_nod *env)
{
	int			i;
	t_core		core;

	core.lst[0] = ft_minishell_parsing(ft_strtrim(str, "\a\b\t\n\v\f\r "), env);
	core.lst[1] = core.lst[0];
	core.p1[0] = -1;
	core.p1[1] = -1;
	core.env = env;
	i = ft_here_doc(core.lst[1], env);
	if (ft_error_heredoc(core.lst[1], env, &i) != 0)
		return ;
	i = 0;
	ft_execute_core(&core, env, str);
}

void	ft_execute_core(t_core *core, t_nod *env, char *str)
{
	int		i;
	int		id;
	int		check;

	check = 0;
	if (core->lst[0] && core->lst[0]->empty == 1)
		return ;
	core = ft_init_execute(core->lst[1], core, &i, &core->tmp_stdin);
	while (core->lst[1])
	{
		if (ft_check(core->lst, env, core->tmp_stdin, core->p1) == 1)
			check = 1;
		if (check == 0)
			if (ft_check_unset_export(core, env, i) == 1)
				return ;
		core->id_tab[i] = ft_init_fork(core->id_tab[i], core->tmp_stdin, check);
		id = ft_init_pipe(core->lst[1], core->p1, core->id_tab[i], i);
		if (check == 0 && str != NULL && id == 0)
			ft_execute_cmd(core, env, core->id_tab, core->p1);
		i = ft_execute_end(core->lst, core->tmp_stdin, i);
		ft_clean_no_perm(core, env, check, id);
		check = 0;
	}
	ft_wait_id(env, core->id_tab);
	ft_clean_end(core->lst[0], core->tmp_stdin, core->p1);
}

int	ft_init_pipe(t_parsed *lst, int p1[2], int id, int i)
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
	if (id != 0 && lst->next != NULL)
		ft_clean_connect(STDIN, p1[0], p1[1]);
	else
		ft_close(p1[0], -1, -1, -1);
	return (id);
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
