/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_to_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:59:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/09 18:48:07 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_heredoc_to_file(char **infile, char *limiter)
{
	int		fd;
	int		stop;
	char	*buffer;

	stop = 0;
	buffer = NULL;
	if (*infile && access(*infile, F_OK) == 0)
		*infile = ft_get_tmpname(infile);
	fd = open(*infile, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | \
		S_IWGRP | S_IROTH);
	while (!stop)
	{
		buffer = get_next_line(STDIN);
		if (!ft_strncmp(buffer, limiter, ft_strlen(limiter)))
			stop++;
		else if (buffer)
			write(fd, buffer, ft_strlen(buffer));
		if (buffer)
			ft_true_free((void **)&buffer);
	}
	buffer = get_next_line(1024 + (STDIN + 1));
	ft_true_free((void **)&limiter);
	return (fd);
}
