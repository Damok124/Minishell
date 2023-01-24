/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:16:21 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/24 13:29:16 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_outfile(t_parsed *lst)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == '>')
			c++;
		if (lst->redirections[i][0] == 'A')
			c++;
		i++;
	}
	return (c);
}

void	ft_choose_outfile(t_parsed *lst)
{
	int	i;
	int	append;
	int	outfile;

	i = 0;
	append = -1;
	outfile = -1;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == '>')
			outfile = i;
		if (lst->redirections[i][0] == 'A')
			append = i;
		i++;
	}
	if (outfile > append)
		ft_outfile_basic(lst);
	if (append > outfile)
		ft_outfile_append(lst);
}

void	ft_outfile_basic(t_parsed *lst)
{
	int	fd;
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == '>')
			c++;
		if (c == ft_check_outfile(lst))
		{
			fd = open(lst->redirections[i] + 1,
					O_CREAT | O_RDWR | O_TRUNC, 0777);
			if (fd < 0)
				exit(-1);
			dup2(fd, STDOUT);
			ft_close(fd, -1, -1, -1);
			return ;
		}
		i++;
	}	
}

void	ft_outfile_append(t_parsed *lst)
{
	int	fd;
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == 'A')
			c++;
		if (c == ft_check_outfile(lst))
		{
			fd = open(lst->redirections[i] + 1,
					O_CREAT | O_RDWR | O_APPEND, 0777);
			if (fd < 0)
				exit(-1);
			dup2(fd, STDOUT);
			ft_close(fd, -1, -1, -1);
			return ;
		}
		i++;
	}	
}
