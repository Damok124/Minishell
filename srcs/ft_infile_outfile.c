/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile_outfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:43:52 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/24 19:11:53 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_file(t_parsed *lst)
{
	int	i;
	int	fd;

	i = 0;
	while (lst && lst->redirections && lst->redirections[i] != NULL)
	{
		if (lst->redirections[i][0] != 'H' && lst->redirections[i][0] != '<')
		{
			fd = open(lst->redirections[i] + 1, O_CREAT, 0644);
			if (fd < 0 && access(lst->redirections[i] + 1, F_OK) == 1)
			{
				perror("open");
				exit(-1);
			}
			fd = close(fd);
		}
		if (ft_check_file_error(lst, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_file_error(t_parsed *lst, int i)
{
	int	ok;

	ok = 0;
	ok = ft_check_in(lst, i);
	if (ok == -1)
		return (-1);
	ok = ft_check_out(lst, i);
	if (ok == -1)
		return (-1);
	ok = ft_check_append(lst, i);
	if (ok == -1)
		return (-1);
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
			ft_true_free((void **)&tmp);
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
			ft_true_free((void **)&tmp);
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
			ft_true_free((void **)&tmp);
			return (ret);
		}
	}
	return (0);
}
