/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:22:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/05 17:01:57 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_child_id;

void	ft_execute_cmd(t_core *core, t_nod *env, int *id_tab, int p1[2])
{
	char	*path;
	char	**tab;
	int		ret_value;

	path = NULL;
	ret_value = 0;
	tab = ft_env_to_tab(env, core->lst);
	if (core->lst[1] && core->lst[1]->cmds)
		path = ft_access(core->lst[1]->cmds[0], ft_get_env("PATH", env));
	if (path == NULL && core->lst[1]->cmds
		&& ft_search_built_in(core->lst[1]) == 0)
		ret_value = ft_cmd_not_found_print(core->lst[1]);
	if (ft_check_infile(core->lst[1]) != 0)
		ft_choose_here_doc_or_infile(core->lst[1], core->lst[1]->empty);
	if (ft_check_outfile(core->lst[1]) != 0)
		ft_choose_outfile(core->lst[1]);
	if (path != NULL && ft_search_built_in(core->lst[1]) == 0 && ret_value == 0)
		ret_value = execve(path, core->lst[1]->cmds, tab);
	else if (ft_search_built_in(core->lst[1]) != 0)
		ret_value = ft_call_built_in(core, env, id_tab);
	ft_clean_pipex_2(core->lst, env, tab, path);
	ft_close(p1[0], p1[1], -1, -1);
	free(id_tab);
	exit(ret_value);
}

int	ft_cmd_not_found_print(t_parsed *lst)
{
	int		i;

	i = 0;
	i = access(lst->cmds[0], W_OK);
	if (ft_strchr(lst->cmds[0], '/') != NULL)
	{
		if (ft_strlen(lst->cmds[0]) == 1)
			ft_putstr_fd("/: Is a directory\n", 2);
		else if (i == 0)
		{
			ft_print_error_double(lst->cmds[0], ": Is a directory\n");
			return (126);
		}
		else if (ft_check_perm(lst->cmds[0]) == 0)
			ft_print_error_double(
				lst->cmds[0], ": No such file or directory\n");
		else
			return (126);
	}
	else
		ft_print_error_double(lst->cmds[0], ": command not found\n");
	return (127);
}

void	ft_clean_exit(t_parsed *lst, t_nod *env, int p1[2])
{
	ft_free_env(env);
	ft_free_parsed(lst);
	ft_close(p1[0], p1[1], -1, -1);
}

char	*ft_access(char *str, char *value)
{
	char	*path;
	int		i;
	char	**env;

	i = 0;
	if (str == NULL || str[0] == '\0' || ft_strncmp(str, "/", 2) == 0)
		return (NULL);
	if (access(str, R_OK) == 0 && access(str, X_OK) == 0
		&& access(str, W_OK) == -1 && ft_strncmp(str, "/", 2) != 0)
		return (str);
	str = ft_strjoin("/", str);
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

char	*ft_check_access(char **env, char **path, char *str)
{
	if (access((*path), R_OK) == 0)
	{
		ft_free_double(env, str);
		return (*path);
	}
	ft_true_free((void **)&(*path));
	(*path) = NULL;
	return (NULL);
	(void)str;
	(void)env;
}
