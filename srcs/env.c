/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:12:18 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/24 18:05:32 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//get the USERNAME in the environment and return it
char	*ft_get_username(t_nod	*env)
{
	char	*username;

	username = ft_strjoin(ft_get_env("USER", env), ":~$");
	return (username);
}
