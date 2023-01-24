/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_connect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:59:39 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/24 18:05:45 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_connect(int std, int toconnect, int toclose)
{
	dup2(toconnect, std);
	if (toconnect != -1)
		close(toconnect);
	if (toclose != -1)
		close(toclose);
}
