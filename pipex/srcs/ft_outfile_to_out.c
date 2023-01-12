/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile_to_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:10 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/09 18:48:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_outfile_to_out(char **paths, int i, char **cmd_a, t_data *data)
{
	int		fdof;
	char	*outfile;

	outfile = data->argv[data->ac - 1];
	fdof = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, \
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fdof > 0)
	{
		dup2(fdof, 1);
		close(fdof);
		if (!fork())
		{
			if (paths[i] && paths[i][0] != '\0')
				execve(paths[i], cmd_a, data->env);
			else
				ft_clean_exit(paths, cmd_a);
		}
	}
	else
		perror(outfile);
	ft_full_free((void **)cmd_a);
}
