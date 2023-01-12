/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:11:56 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/09 18:48:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>

/////////////////////////
//	DEFINES
/////////////////////////

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define READ_END 0
# define WRITE_END 1

/////////////////////////
//	STRUCTURES
/////////////////////////

typedef struct s_data {
	int		ac;
	char	**argv;
	char	**env;
}			t_data;

/////////////////////////
//	INITIALIZATION
/////////////////////////

t_data	ft_init_data(int ac, char **argv, char **env);

/////////////////////////
//	COMMANDS
/////////////////////////

char	**ft_parse_cmd(char *arg);
void	ft_cmd_not_found(char *str);
void	ft_print_cmderr(char **validpaths, char **argv);

/////////////////////////
//	TESTS
/////////////////////////

int		ft_such_file(char *filename);
int		ft_test_files(char **argv, int ac);

/////////////////////////
//	REDIRECTIONS
/////////////////////////

void	ft_outfile_to_out(char **paths, int i, char **cmd_a, t_data *data);
void	ft_append_to_outfile(char **paths, int i, char **cmd_a, t_data *data);
int		ft_outfile_permission(char *filename);
void	ft_infile_to_in(char **argv, char **cmd_args, char **validpaths, int i);
int		ft_infile_permission(char *filename);
void	ft_clean_connect(int std, int toconnect, int toclose);

/////////////////////////
//	PATHS PARSING
/////////////////////////

char	**ft_get_paths(char **env);
char	**ft_get_fullpaths(char **paths, char *cmd);
char	**ft_get_validpaths(int ac, char **argv, char **paths);
char	*ft_get_goodpath(char **cmd, char **fullpaths);

/////////////////////////
//	TMP_FILE
/////////////////////////

int		ft_check_tmpname(char *tmpname);
char	*ft_get_tmpname(char **basename);

/////////////////////////
//	HERE_DOC
/////////////////////////

char	*ft_setup_limiter(const char *src);
int		ft_heredoc_to_file(char **infile, char *limiter);
char	*ft_heredoc_to_in(char **argv, char **cmd_args, char **vpaths, int i);
void	ft_parent_hdoc(t_data *data, char **cmd_args, char **validpaths, int i);

/////////////////////////
//	EXITING
/////////////////////////

void	ft_clean_exit(char **validpaths, char **cmd_args);
void	ft_double_fullfree(char **strs1, char **strs2);
void	ft_unlink_and_free(char *filename);
void	ft_close_stdfds(void);

#endif
