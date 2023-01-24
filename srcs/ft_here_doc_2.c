/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:37:34 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/24 13:51:37 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_mini_check_here_doc(t_parsed *lst)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (lst && lst->redirections && lst->redirections[i])
	{
		if (lst->redirections[i][0] == 'H')
			c++;
		i++;
	}
	return (c);
}

int	ft_check_here_doc(t_parsed *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i += ft_mini_check_here_doc(lst);
		lst = lst->next;
	}
	return (i);
}

int	ft_init_fd(int c)
{
	int		fd;
	char	*str;
	char	*tmp;

	tmp = ft_itoa(c);
	str = ft_strjoin(HEREDOC, tmp);
	fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	free(str);
	free(tmp);
	return (fd);
}

int	ft_error_heredoc(t_parsed *lst, t_nod *env, int *i)
{
	if (*i != 0)
	{
		ft_free_parsed(lst);
		ft_return_value(130, env);
		*i = 130;
		return (1);
	}
	return (0);
}

void	ft_clean_here_doc(t_parsed *lst, t_nod *env, char *str, int fd)
{
	if (fd != -1)
		close(fd);
	free(str);
	ft_free_parsed(lst);
	ft_free_env(env);
	exit(130);
}
