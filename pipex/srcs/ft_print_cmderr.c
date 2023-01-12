/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmderr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:14 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/09 18:48:20 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_cmderr(char **validpaths, char **argv)
{
	char	**cmd_args;
	int		i;

	i = 0;
	if (!ft_strncmp(argv[1], "here_doc", 9))
		argv = argv + 1;
	while (validpaths && validpaths[i])
	{
		if (validpaths[i][0] == '\0')
		{
			cmd_args = ft_split(argv[i + 2], ' ');
			ft_cmd_not_found(cmd_args[0]);
			ft_full_free((void **)cmd_args);
		}
		i++;
	}
}
