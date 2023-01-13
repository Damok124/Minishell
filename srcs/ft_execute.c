/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:01:46 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/13 13:39:18 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_child_id;

int	ft_execute(char *str, t_nod *env)
{
	t_parsed	*lst;
	t_parsed	*head;
	int			p1[2];
	int			id;
	int			i;
	int			stock[2];

	i = 0;
	stock[0] = dup(STDIN);
	stock[1] = dup(STDOUT);
	head = ft_minishell_parsing(ft_strdup(str), env);
	//ft_show_lst_parsed(head);
	lst = head;
	i = ft_here_doc(lst);
	if (i != 0)
	{
		printf("\n%d\n", i);
		if (i == -1)
			return (0);
		else
			return (130);
	}
	if (g_child_id == -2)
		return (0);
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
		str = ft_strjoin(HEREDOC, ft_itoa(i));
		unlink(str);
		free(str);
		i++;
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
