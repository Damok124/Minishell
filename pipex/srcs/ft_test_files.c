/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:19 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/09 18:48:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_test_files(char **argv, int ac)
{
	if (ac >= 5 && ft_strncmp(argv[1], "here_doc", 9))
	{
		if (ft_such_file(argv[1]))
			ft_infile_permission(argv[1]);
	}
	if (!ft_outfile_permission(argv[ac - 1]))
		return (0);
	return (1);
}
