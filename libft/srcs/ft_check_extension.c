/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:10:05 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 15:25:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_extension(char *filename, char *extension)
{
	size_t	filename_len;
	size_t	extension_len;
	int		i;

	i = 0;
	if (filename[0] && filename[0] == '.' && filename[1] && filename[1] == '/')
		filename += 2;
	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(extension);
	if (!filename || !extension || filename_len <= extension_len || \
		extension_len < 2)
		return (0);
	while (filename[i] && filename[i] != '.')
		i++;
	if (i > 0 && filename[i])
	{
		filename += i;
		i = 0;
		while (filename[i] && extension[i] && filename[i] == extension[i])
			i++;
		if (extension[i] == '\0' && filename[i] == '\0')
			return (1);
	}
	return (0);
}
