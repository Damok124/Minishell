/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:44:38 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/23 18:35:12 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_child_id;

int	ft_create_here_doc(t_parsed *lst, t_nod *env, int c)
{
	int		fd;
	int		i;

	i = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == 'H')
		{
			if (i + 1 != ft_check_here_doc_or_infile(lst))
				ft_fake_here_doc(lst, env, i);
			if (i + 1 == ft_check_here_doc_or_infile(lst))
				fd = ft_real_here_doc(lst, env, i, c);
		}
		i++;
	}
	return (fd);
}

int	ft_here_doc(t_parsed *lst, t_nod *env)
{
	int	i;

	i = 0;
	if (ft_check_here_doc(lst) == 0)
		return (0);
	while (lst && lst->redirections && lst != NULL)
	{
		if (ft_mini_check_here_doc(lst) > 0)
		{
			g_child_id = fork();
			if (g_child_id == 0)
				ft_exit_here_doc_status(lst, i, env);
			else
				waitpid(g_child_id, &g_child_id, 0);
			if (g_child_id != 0)
				return (g_child_id);
			if (g_child_id == 33280)
				return (-1);
		}
		lst = lst->next;
		i++;
	}
	return (0);
}

int	ft_real_here_doc(t_parsed *lst, t_nod *env, int i, int c)
{
	int		fd;
	char	*str;
	int		j;

	j = 0;
	fd = ft_init_fd(c);
	if (fd < 0)
		exit(1);
	while (1)
	{
		str = readline("< ");
		if (g_child_id == 666)
			ft_clean_here_doc(lst, env, str, fd);
		if (str == NULL)
		{
			printf(HRM, lst->redirections[i] + 1);
			close(fd);
			return (fd);
		}
		if (ft_check_str_here_doc(lst, str, i, fd) == 1)
			break ;
		j++;
	}
	close(fd);
	return (fd);
}

int	ft_check_str_here_doc(t_parsed *lst, char *str, int i, int fd)
{
	char	*tmp;

	if (str && lst->redirections && ft_strncmp(str, lst->redirections[i]
			+ 1, ft_strlen(lst->redirections[i] + 1) + 1) == 0)
	{
		free(str);
		return (1);
	}
	if (str != NULL)
	{
		tmp = ft_strjoin(str, "\n");
		ft_putstr_fd(tmp, fd);
		free(tmp);
	}
	if (str != NULL)
		free(str);
	return (0);
}

int	ft_fake_here_doc(t_parsed *lst, t_nod *env, int i)
{
	char	*str;

	while (1)
	{
		str = readline("< ");
		if (g_child_id == 666)
			ft_clean_here_doc(lst, env, str, -1);
		if (ft_strncmp(str, lst->redirections[i] + 1, \
			ft_strlen(lst->redirections[i] + 1)) == 0)
		{
			free(str);
			return (0);
		}
		if (str == NULL)
		{
			printf("Minishell: warning: here-document delimited by ");
			printf("end-of-file (wanted '%s')\n", lst->redirections[i] + 1);
			free(str);
			return (-1);
		}
		free(str);
	}
	return (0);
}
