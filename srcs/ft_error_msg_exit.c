/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:03:11 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/27 16:13:18 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_msg(t_parsed *lst)
{
	char	*str;
	char	*str_2;

	str = ft_strjoin("Minishell: exit: ", lst->cmds[1]);
	str_2 = ft_strjoin(str, ": numeric argument required\n");
	ft_putstr_fd(str_2, 2);
	free(str);
	free(str_2);
}
