/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:36:04 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/04 15:55:11 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_choose_here_doc_or_infile(t_parsed *lst, int c)
{
	int		here_doc;
	int		infile;
	int		fd;
	int		i;
	char	*str;

	i = 0;
	here_doc = -1;
	infile = -1;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == '<')
			infile = i;
		if (lst->redirections[i][0] == 'H')
			here_doc = i;
		i++;
	}
	if (infile > here_doc)
		fd = ft_infile_basic(lst);
	if (here_doc > infile)
	{
		str = ft_strjoin(HEREDOC, ft_itoa(c));
		fd = open(str, O_CREAT | O_RDONLY, 0644);
		free(str);
	}
	dup2(fd, 0);
	close(fd);
}

int	ft_infile_basic(t_parsed *lst)
{
	int	fd;
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == '<')
			c++;
		if (c == ft_check_infile(lst))
		{
			fd = open(lst->redirections[i] + 1, O_CREAT | O_RDWR , 0777);
			if (fd < 0)
				exit(-1);
			dup2(fd, STDIN);
			return (fd);
		}
		i++;
	}
	return (0);
}

int	ft_check_infile(t_parsed *lst)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == '<')
			c++;
		if (lst->redirections[i][0] == 'H')
			c++;
		i++;
	}
	return (c);
}
