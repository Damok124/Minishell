/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_validpaths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:59:57 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/09 18:48:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_validpaths(int ac, char **argv, char **paths)
{
	int		i;
	char	**cmd;
	char	**fullpaths;
	char	**validpaths;

	i = 0;
	validpaths = (char **)malloc(sizeof(char *) * ac - 2);
	if (!validpaths)
		return (NULL);
	validpaths[ac - 3] = NULL;
	while (i < ac - 3)
	{
		cmd = ft_parse_cmd(argv[i + 2]);
		fullpaths = ft_get_fullpaths(paths, cmd[0]);
		validpaths[i] = ft_get_goodpath(cmd, fullpaths);
		ft_full_free((void **)cmd);
		ft_full_free((void **)fullpaths);
		i++;
	}
	return (validpaths);
}
