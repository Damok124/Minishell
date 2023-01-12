/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:59:42 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/09 18:47:50 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_exit(char **validpaths, char **cmd_args)
{
	ft_double_fullfree(validpaths, cmd_args);
	ft_close_stdfds();
	exit(1);
}
