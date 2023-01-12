/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile_to_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:04 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/09 18:48:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_infile_to_in(char **argv, char **cmd_args, char **validpaths, int i)
{
	int		fd;

	fd = -1;
	if (i == 1 && argv[1] && !access(argv[1], F_OK))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			dup2(fd, STDIN);
			close(fd);
		}
		else
			ft_clean_exit(validpaths, cmd_args);
	}
	else if (i == 1 && argv[1] && access(argv[1], F_OK))
		ft_clean_exit(validpaths, cmd_args);
}
