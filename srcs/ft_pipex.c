/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:22:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/18 19:35:12 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_child_id;

void	ft_pipex(t_parsed *lst[2], t_nod *env, int i, int p1[2])
{
	char	*path;
	char	**tab;
	int		ret_value;

	path = NULL;
	ret_value = 0;
	tab = ft_env_to_tab(env);
	if (lst[1] && lst[1]->cmds && lst[1]->cmds[0])
		path = ft_access(lst[1]->cmds[0], ft_get_env("PATH", env));
	if (path == NULL && lst[1]->cmds && lst[1]->cmds[0]
		&& ft_search_built_in(lst[1]) == 0)
	{
		printf("%s:  command not found\n", lst[1]->cmds[0]);
		ret_value = 127;
	}
	if (ft_check_infile(lst[1]) != 0)
		ft_choose_here_doc_or_infile(lst[1], i);
	if (ft_check_outfile(lst[1]) != 0)
		ft_choose_outfile(lst[1]);
	if (path != NULL && ft_search_built_in(lst[1]) == 0)
		execve(path, lst[1]->cmds, tab);
	else if (ft_search_built_in(lst[1]) != 0)
		ret_value = ft_call_built_in(lst[1], lst[0], env);
	ft_clean_pipex(lst[0], env, tab, path);
	ft_close(p1[0], p1[1], -1, -1);
	exit(ret_value);
}

void	ft_clean_pipex(t_parsed *lst, t_nod *env, char **tab, char *path)
{
	ft_free_double(tab, path);
	ft_free_env(env);
	ft_free_parsed(lst);
}

int	ft_call_built_in(t_parsed *lst, t_parsed *head, t_nod *env)
{
	int	ret;

	ret = 0;
	if (lst && lst->cmds && ft_search_built_in(lst) == 1)
		ft_echo(lst->cmds);
	if (lst && lst->cmds && ft_search_built_in(lst) == 2)
		ret = ft_cd(lst->cmds, env, 0);
	if (lst && lst->cmds && ft_search_built_in(lst) == 3)
		ft_pwd(lst->cmds);
	if (lst && lst->cmds && ft_search_built_in(lst) == 4)
		ft_export(lst->cmds, env, 1);
	if (lst && lst->cmds && ft_search_built_in(lst) == 5)
		ft_unset(lst->cmds, env);
	if (lst && lst->cmds && ft_search_built_in(lst) == 6)
		ft_env(env);
	if (lst && lst->cmds && ft_search_built_in(lst) == 7)
		ft_exit(lst, head, env);
	return (ret);
}

char	*ft_access(char *str, char *value)
{
	char	*path;
	int		i;
	char	**env;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (access(str, R_OK) == 0 && access(str, X_OK) == 0)
		return (str);
	str = ft_strjoin("/", str);
	env = ft_split(value, ':');
	i = 0;
	while (env[i])
	{
		path = ft_strjoin(env[i], str);
		i++;
		path = ft_check_access(env, path, str);
		if (path != NULL)
			return (path);
		free(path);
	}
	ft_free_double(env, str);
	return (NULL);
}

void	ft_free_double(char **str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	free(str2);
}

char	*ft_check_access(char **env, char *path, char *str)
{
	if (access(path, R_OK) == 0)
	{
		ft_free_double(env, str);
		return (path);
	}
	free(path);
	return (NULL);
}
