/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:44:38 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/18 15:26:42 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_child_id;

int	ft_check_here_doc_or_infile(t_parsed *lst)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == 'H')
			c++;
		if (lst->redirections[i][0] == '<')
			c++;
		i++;
	}
	return (c);
}

int	ft_create_here_doc(t_parsed *lst, int c)
{
	int		fd;
	int		i;

	i = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == 'H')
		{
			if (i + 1 != ft_check_here_doc_or_infile(lst))
				ft_fake_here_doc(lst, i);
			if (i + 1 == ft_check_here_doc_or_infile(lst))
				fd = ft_real_here_doc(lst, i, c);
		}
		i++;
	}
	return (fd);
}

int	ft_here_doc(t_parsed *lst)
{
	int	i;
	int	res;

	i = 0;
	if (ft_check_here_doc(lst) == 0)
		return (0);
	while (lst && lst->redirections && lst != NULL)
	{
		if (ft_mini_check_here_doc(lst) > 0)
		{
			g_child_id = fork();
			if (g_child_id == 0)
			{
				res = ft_create_here_doc(lst, i);
				if (res == -1)
					exit (-1);
				exit(0);
			}
			else
				waitpid(g_child_id, &g_child_id, 0);
			if (g_child_id != 0)
				return (g_child_id);
			if (g_child_id == 33280) //////////////////////////////////////////
				return (-1);
		}
		lst = lst->next;
		i++;
	}
	return (0);
}

int	ft_real_here_doc(t_parsed *lst, int i, int c)
{
	int		fd;
	char	*str;
	char	*tmp;

	str = ft_strjoin(HEREDOC, ft_itoa(c));
	fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	free(str);
	if (fd < 0)
		exit(1);
	while (1)
	{
		str = readline("< ");
		if (str == NULL)
		{
			printf("Minishell: warning: here-document delimited by ");
			printf("end-of-file (wanted `%s')\n", lst->redirections[i] + 1);
			close(fd);
			return (-1);
		}
		if (str && lst && lst->redirections && ft_strncmp(str,
				lst->redirections[i] + 1, ft_strlen(lst->redirections[i] + 1) + 1) == 0)
		{
			free(str);
			break ;
		}
		if (str != NULL)
		{
			tmp = ft_strjoin(str, "\n");
			ft_putstr_fd(tmp, fd);
			free(tmp);
		}
		if (str != NULL)
			free(str);
	}
	close(fd);
	// str = ft_strjoin(HEREDOC, ft_itoa(c));
	// fd = open(str, O_CREAT | O_RDONLY, 0644);
	// free(str);
	return (fd);
}

void	ft_fake_here_doc(t_parsed *lst, int i)
{
	char	*str;

	while (1)
	{
		str = readline("< ");
		if (ft_strncmp(str, lst->redirections[i] + 1, \
			ft_strlen(lst->redirections[i] + 1)) == 0)
		{
			free(str);
			break ;
		}
		free(str);
	}
}
