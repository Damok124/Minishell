/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile_outfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:43:52 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/06 18:06:39 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_file(t_parsed *lst)
{
	int	i;
	int	fd;
	int	ok;

	i = 0;
	while (lst && lst->redirections && lst->redirections[i] != NULL)
	{
		if (lst->redirections[i][0] != '<')
		{
			fd = open(lst->redirections[i] + 1, O_CREAT, 0644);
			if (fd < 0 && access(lst->redirections[i] + 1, F_OK) == 1)
			{
				perror("open");
				exit(-1);
			}
			fd = close(fd);
		}
		ok = ft_check_in(lst, i);
		if (ok == -1)
			return (-1);
		ok = ft_check_out(lst, i);
		if (ok == -1)
			return (-1);
		ok = ft_check_append(lst, i);
		if (ok == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_out(t_parsed *lst, int i)
{
	char	*tmp;
	int		ret;

	if (lst->redirections[i][0] == '>')
	{
		ret = access(lst->redirections[i] + 1, W_OK);
		if (ret == -1)
		{
			tmp = ft_strjoin("Minishell: ", lst->redirections[i] + 1);
			perror(tmp);
			free(tmp);
			return (i);
		}
	}
	return (0);
}

int	ft_check_append(t_parsed *lst, int i)
{
	char	*tmp;
	int		ret;

	if (lst->redirections[i][0] == 'A')
	{
		ret = access(lst->redirections[i] + 1, W_OK);
		if (ret == -1)
		{
			tmp = ft_strjoin("Minishell: ", lst->redirections[i] + 1);
			perror(tmp);
			free(tmp);
			return (i);
		}
	}
	return (0);
}

int	ft_check_in(t_parsed *lst, int i)
{
	char	*tmp;
	int		ret;

	if (lst->redirections[i][0] == '<')
	{
		ret = access(lst->redirections[i] + 1, R_OK);
		if (ret == -1)
		{
			tmp = ft_strjoin("Minishell: ", lst->redirections[i] + 1);
			perror(tmp);
			free(tmp);
			return (ret);
		}
	}
	return (0);
}
