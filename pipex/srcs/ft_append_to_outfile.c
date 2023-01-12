/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_to_outfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:59:07 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/09 18:47:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_append_to_outfile(char **paths, int i, char **cmd_a, t_data *data)
{
	int		fdof;
	char	*outfile;

	outfile = data->argv[data->ac - 1];
	fdof = open(outfile, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | \
		S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fdof > 0)
	{
		dup2(fdof, 1);
		close(fdof);
		if (paths[i] && paths[i][0] != '\0')
		{
			if (!fork())
				execve(paths[i], cmd_a, data->env);
		}
	}
	else
		perror(outfile);
	ft_full_free((void **)cmd_a);
}
