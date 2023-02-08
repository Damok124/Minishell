/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:31:21 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/08 18:52:57 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_access(t_parsed *lst, char *str, char *value)
{
	char		*path;
	int			i;
	char		**env;

	if (ft_big_check_access(lst, str, 0) == 1)
		return (str);
	if (ft_check_dir_file(lst, str) == 1)
		return (NULL);
	if (ft_big_check_access(lst, str, 1) == 1)
		return (lst->cmds[0]);
	str = ft_strjoin("/", lst->cmds[0]);
	env = ft_split(value, ':');
	i = 0;
	while (env[i])
	{
		path = ft_strjoin(env[i], str);
		i++;
		path = ft_check_access(env, &path, str);
		if (path != NULL)
			return (path);
		ft_true_free((void **)&path);
		path = NULL;
	}
	ft_free_double(env, str);
	return (NULL);
}

int	ft_big_check_access( t_parsed *lst, char *str, int type)
{
	if (type == 0)
	{
		if (access(str, R_OK) == 0 && access(str, X_OK) == 0
			&& access(str, W_OK) == -1 && ft_strncmp(str, "/", 2) != 0)
			return (1);
	}
	if (type == 1)
	{
		str = lst->cmds[0];
		if (access(lst->cmds[0], F_OK) == 0 && access(lst->cmds[0], X_OK) == 0
			&& ft_strncmp(lst->cmds[0], "./", 2) != 0)
			return (1);
	}
	return (0);
}

int	ft_check_dir_file(t_parsed *lst, char *str)
{
	struct stat	sb;
	char		*path;
	int			i;

	i = stat(str, &sb);
	if (ft_strncmp(str, "./", 2) == 0 && access(str + 2, F_OK) == 0
		&& access(str + 2, X_OK) == 0 && i != -1 && S_ISREG(sb.st_mode))
	{
		path = ft_strdup(str + 2);
		free(str);
		lst->cmds[0] = path;
		return (0);
	}
	if (str == NULL || str[0] == '\0' || ft_strncmp(str, "/", 2) == 0)
		return (1);
	if (ft_strncmp(str, "./", 2) == 0 && access(str + 2, R_OK) == 0)
		return (1);
	if (ft_strncmp(str, "./", 2) == 0 && (stat(str + 2, &sb) == -1
			|| (sb.st_mode & S_IFMT) != S_IFREG))
		return (1);
	if (i != -1 && S_ISDIR(sb.st_mode))
		return (1);
	return (0);
}

char	*ft_check_access(char **env, char **path, char *str)
{
	if (access((*path), F_OK) == 0)
	{
		ft_free_double(env, str);
		return (*path);
	}
	ft_true_free((void **)&(*path));
	(*path) = NULL;
	return (NULL);
	(void)str;
}
