/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:01:46 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/09 17:51:39 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute(char *str, t_nod *env)
{
	t_parsed	*lst;
	t_parsed	*head;
	int			p1[2];
	// int			p2[2];
	int			id;
	int			i;
	int			stock[2];

	i = 0;
	stock[0] = dup(STDIN);
	stock[1] = dup(STDOUT);
	head = ft_minishell_parsing(ft_strdup(str), env);
	//ft_show_lst_parsed(head);
	lst = head;
	while (lst)
	{
		while (lst && lst->redirections && ft_check_file(lst) == -1)
		{
			lst = lst->next;
			if (!lst)
			{
				ft_free_parsed(head);
				return (-1);
			}
		}
		ft_here_doc(lst);
		if (lst->cmds && lst->cmds[0] && ft_strncmp(lst->cmds[0], "exit", 5) == 0)
		{
			free(head);
			free(str);
			exit(0);
		}
		if (pipe(p1) == -1)
			exit(-1);
		id = fork();
		if (id == -1)
			exit(1);
		ft_init_pipe(lst, p1, id);
		if (str != NULL && id == 0)
			ft_pipex(lst, env, i);
		if (id != 0)
			waitpid(id, &id, 0);
		lst = lst->next;
		i++;
		unlink(".tmp_here_doc_tmpfile_touch_it_and_you_will_die_!");
		if (lst == NULL)
			dup2(stock[0], STDIN);
	}
	ft_free_parsed(head);
	//printf("Exit status is %d\n", id);
	return (id);
}

void	ft_init_pipe(t_parsed *lst, int p1[2], int id)
{
	int j;

	j = 0;
	j = ft_do_need_pipe(lst, j);
	if (j == 3)
		return ;
	if (id == 0)
	{
		if (lst != NULL && lst->next != NULL)
		{
			ft_clean_connect(STDOUT, p1[1], p1[0]);
		}
		//ft_clean_connect(STDIN, p1[0], p1[1]);
	}
	else if (id != 0)
	{
			ft_clean_connect(STDIN, p1[0], p1[1]);
		//ft_clean_connect(STDOUT, p1[1], p1[0]);
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
	// printf("%d\n", j);
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
