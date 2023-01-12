/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_to_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:00 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/09 18:48:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_heredoc_to_in(char **argv, char **cmd_args, char **vpaths, int i)
{
	int		fd;
	char	*limiter;
	char	*infile;

	if (i == 1)
	{
		infile = ft_strdup("tmp_pipex");
		limiter = ft_setup_limiter(argv[2]);
		fd = ft_heredoc_to_file(&infile, limiter);
		if (fd > 0)
		{
			close(fd);
			fd = open(infile, O_RDONLY);
			if (fd < 0)
				ft_clean_exit(vpaths, cmd_args);
			dup2(fd, STDIN);
			close(fd);
			return (infile);
		}
		else
			ft_clean_exit(vpaths, cmd_args);
	}
	return (NULL);
}
