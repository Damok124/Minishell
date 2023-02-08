/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:22:15 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/08 18:17:50 by tlarraze         ###   ########.fr       */
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
		path = ft_access(core->lst[1], core->lst[1]->cmds[0],
				ft_get_env("PATH", env));
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
	int			i;

	i = 0;
	i = access(lst->cmds[0], W_OK);
	if (ft_strchr(lst->cmds[0], '/') != NULL)
	{
		if (ft_strlen(lst->cmds[0]) == 1)
			ft_putstr_fd("/: Is a directory\n", 2);
		else if (ft_call_print_error(lst, i) == 126)
			return (126);
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

int	ft_call_print_error(t_parsed *lst, int i)
{
	struct stat	sb;
	int			check;

	if (ft_strncmp(lst->cmds[0], "./", 2) == 0)
		check = stat(lst->cmds[0] + 2, &sb);
	else
		check = stat(lst->cmds[0], &sb);
	if (check != -1 && S_ISREG(sb.st_mode))
	{
		ft_print_error_double(lst->cmds[0], ": Permission denied\n");
		return (126);
	}
	else if (i == 0)
	{
		ft_print_error_double(lst->cmds[0], ": Is a directory\n");
		return (126);
	}
	return (0);
}

void	ft_clean_exit(t_parsed *lst, t_nod *env, int p1[2])
{
	ft_free_env(env);
	ft_free_parsed(lst);
	ft_close(p1[0], p1[1], -1, -1);
}
