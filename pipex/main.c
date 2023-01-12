/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/05 17:41:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_heredoc(t_data *data, char **validpaths, char *infile)
{
	int			pfds[2];
	char		**cmd_args;
	static int	i;

	i++;
	cmd_args = ft_split(data->argv[i + 2], ' ');
	pipe(pfds);
	if (i == 1 && !infile)
		infile = ft_heredoc_to_in(data->argv, cmd_args, validpaths, i);
	if (i == 1 && infile)
		ft_unlink_and_free(infile);
	if (validpaths[i - 1] && validpaths[i - 1][0] != '\0' && !fork())
	{
		ft_clean_connect(STDOUT, pfds[WRITE_END], pfds[READ_END]);
		execve(validpaths[i - 1], cmd_args, data->env);
	}
	else
	{
		ft_clean_connect(STDIN, pfds[READ_END], pfds[WRITE_END]);
		ft_full_free((void **)cmd_args);
		if ((i + 1) < (data->ac - 4))
			ft_pipex_heredoc(data, validpaths, infile);
		else
			ft_parent_hdoc(data, cmd_args, validpaths, i);
	}
}

void	ft_pipex(t_data *data, char **validpaths)
{
	int			pfds[2];
	char		**cmd_args;
	static int	i;

	i++;
	cmd_args = ft_split(data->argv[i + 1], ' ');
	pipe(pfds);
	if (validpaths[i - 1] && validpaths[i - 1][0] != '\0' && !fork())
	{
		ft_clean_connect(STDOUT, pfds[WRITE_END], pfds[READ_END]);
		ft_infile_to_in(data->argv, cmd_args, validpaths, i);
		execve(validpaths[i - 1], cmd_args, data->env);
	}
	else
	{
		ft_clean_connect(STDIN, pfds[READ_END], pfds[WRITE_END]);
		ft_full_free((void **)cmd_args);
		if ((i + 1) < (data->ac - 3))
			ft_pipex(data, validpaths);
		else
		{
			cmd_args = ft_split(data->argv[i + 2], ' ');
			ft_outfile_to_out(validpaths, i, cmd_args, data);
		}
	}
}

int	main_bonus(t_data *data)
{
	char	**paths;
	char	**validpaths;
	char	*infile;

	infile = NULL;
	paths = ft_get_paths(data->env);
	validpaths = ft_get_validpaths(data->ac - 1, data->argv + 1, paths);
	ft_full_free((void **)paths);
	if (ft_test_files(data->argv, data->ac))
		ft_pipex_heredoc(data, validpaths, infile);
	ft_print_cmderr(validpaths, data->argv);
	waitpid(-1, NULL, 0);
	ft_full_free((void **)validpaths);
	return (1);
}

int	main(int ac, char **argv, char **env)
{
	t_data	data;
	char	**paths;
	char	**validpaths;

	data = ft_init_data(ac, argv, env);
	if (ac >= 6 && !ft_strncmp(argv[1], "here_doc", 9))
		main_bonus(&data);
	else if (ac >= 5 && ft_strncmp(argv[1], "here_doc", 9))
	{
		paths = ft_get_paths(env);
		validpaths = ft_get_validpaths(ac, argv, paths);
		ft_full_free((void **)paths);
		if (ft_test_files(argv, ac))
			ft_pipex(&data, validpaths);
		ft_print_cmderr(validpaths, argv);
		waitpid(-1, NULL, 0);
		ft_full_free((void **)validpaths);
	}
	else
		write(2, "ERROR : wrong number of arguments.\n", 35);
	ft_close_stdfds();
	return (0);
}
