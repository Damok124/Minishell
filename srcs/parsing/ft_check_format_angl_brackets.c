/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_angl_brackets.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:58:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 12:08:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_format_angl_brackets(char *src, char *trans)
{
	char	**needle;
	int		test;
	int		i;

	i = -1;
	test = 1;
	needle = ft_get_wrong_angl_brackets();
	while (needle[++i] && test)
	{
		if (ft_strnstr(trans, needle[i], ft_strlen(trans)))
			test = 0;
	}
	i = ft_strlen(trans);
	if (i >= 2 && trans[i - 2] && ft_strchr("<>", trans[i - 2]) && test)
		if (ft_strchr("\t\n \"\'#&*./|~<>", src[i - 1]) \
			|| (!ft_isprint(src[i - 1])))
				test = 0;
	if (i >= 1 && trans[i - 1] && ft_strchr("<>", trans[i - 1]) && test)
		test = 0;
	ft_full_free((void **)needle);
	if (test)
		test = ft_check_arg_angl_brackets(trans);
	if (!test)
		return (0);
	return (1);
}
