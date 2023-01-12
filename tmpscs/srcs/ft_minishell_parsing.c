/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:34:36 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/10 22:42:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//cat<<EOF>file| wc -c | tr -d " " > file2 | echo "$USER" >> file2 | echo '$HOME' >> file2 | echo '"$USER"' >> file2 | "e"c'h'o"""""""" salut

char	***ft_minishell_parsing(char *src)
{
	char	***dest;
	char	**tmp;
	int		len;
	int		i;

	len = ft_count_strs(src, '|');
	dest = (char ***)malloc(sizeof(char **) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = NULL;
	tmp = ft_split(src, '|');
	while (dest[i])
	{
		dest[i] = ft_smart_split(tmp[i], ' ');
		i++;
	}
	dest =
	return (dest);
}
