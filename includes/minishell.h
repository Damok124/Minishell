/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:11:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/19 18:33:03 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "pipex.h"///////////////////////////////////////
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <wait.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <dirent.h>

typedef struct s_nod
{
	char			*key;
	char			*value;
	struct s_nod	*next;
}					t_nod;

typedef struct s_parsed
{
	int				empty;
	char			**cmds;
	char			**redirections;
	int				cmds_quant;
	int				redir_quant;
	int				hdocs_quant;
	struct s_parsed	*next;
}					t_parsed;

typedef struct s_twins
{
	char			**src;
	char			**trans;
	struct s_twins	*next;
}			t_twins;
/////////////////////////
//	DEFINES
/////////////////////////
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define READ_END 0
# define WRITE_END 1
# define HEREDOC ".tmp_here_doc_tmpfile_touch_it_and_you_will_die_!"
# define HRM "Minishell: warning: delimited by end-of-file (wanted `%s')\n"
/*
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
//	PROMPT
/////////////////////////

*/
char		*ft_get_username(t_nod *env);
int			ft_test(void);
char		*ft_get_env(char *str, t_nod *env);
/*

/////////////////////////
//	BUILD IN
/////////////////////////

*/
//		ft_echo
void		ft_echo(char **str);
void		ft_echo_n(char **str);
int			ft_check_echo_n(char *str);
////////////////////////////////////////////////////////////////
//		ft_export
void		ft_export(char **str, t_nod *env, int doo);
int			ft_fuse_export(t_nod *nod, char *str);
void		ft_show_declare(t_nod *env);
int			ft_exporting(t_nod *big_nod[3], char **str, int found, int i);
int			ft_make_nod(t_nod *big_nod[3], char **str, int i, int found);
////////////////////////////////////////////////////////////////
int			ft_cd(char **str, t_nod *env, int i);
void		ft_pwd(char **str);
void		ft_unset(char **str, t_nod *env);
void		ft_env(t_nod *env);
t_nod		*ft_init_lst(char **env);
t_nod		*ft_init_nod(char *str);
char		**ft_env_to_tab(t_nod *nod);
////////////////////////////////////////////////////////////////
//		ft_export
void		ft_exit(t_parsed *lst, t_parsed *head, t_nod *env);
int			ft_exit_2(t_parsed *lst, t_parsed *head, t_nod *env);
void		ft_check_exit_arg(t_parsed *lst, t_parsed *head, t_nod *env);
////////////////////////////////////////////////////////////////
int			ft_check_unset_export(t_parsed *lst, t_parsed *head,
				t_nod *env, int i);
void		ft_fuse_end_env(t_nod *first, char **strs);
void		ft_free_env(t_nod *env);
void		ft_file_destroy(char *str, int i);
void		ft_return_value(int value, t_nod *env);
int			ft_check_file_error(t_parsed *lst, int i);

/////////////////////////
//	EXEC
/////////////////////////
int			ft_cmd_not_found_print(t_parsed *lst);
int			ft_clean_end(t_parsed *lst, int tmp_stdin, int p1[2]);
void		ft_clean_pipex(t_parsed *lst, t_nod *env, char **tab, char *path);
void		ft_while(t_nod *env_nod);
int			ft_execute(char *str, t_nod *env);
void		ft_pipex(t_parsed *lst[2], t_nod *env, int i, int p1[2]);
char		*ft_access(char *str, char *value);
void		ft_free_double(char **str, char *str2);
char		*ft_check_access(char **env, char *path, char *str);
int			ft_redirection(t_parsed *lst);
int			ft_check_file(t_parsed *lst);
int			ft_infile(t_parsed *lst);
int			ft_check_in(t_parsed *lst, int i);
int			ft_check_append(t_parsed *lst, int i);
int			ft_check_out(t_parsed *lst, int i);
int			ft_check_file(t_parsed *lst);
int			ft_check_outfile(t_parsed *lst);
void		ft_choose_outfile(t_parsed *lst);
void		ft_outfile_basic(t_parsed *lst);
void		ft_outfile_append(t_parsed *lst);
int			ft_infile_basic(t_parsed *lst);
int			ft_check_infile(t_parsed *lst);
void		ft_init_pipe(t_parsed *lst, int p1[2], int id);
int			ft_do_need_pipe(t_parsed *lst, int j);
void		ft_close(int a, int b, int c, int d);
int			ft_search_built_in(t_parsed *lst);
int			ft_call_built_in(t_parsed *lst, t_parsed *head, t_nod *env);
/////////////////////////
//	HERE_DOC
/////////////////////////
int			ft_here_doc(t_parsed *lst, t_nod *env);
int			ft_here_doc_basic(int c);
int			ft_check_here_doc_or_infile(t_parsed *lst);
void		ft_choose_here_doc_or_infile(t_parsed *lst, int i);
int			ft_fake_here_doc(t_parsed *lst, t_nod *env, int i);
int			ft_check_str_here_doc(t_parsed *lst, char *str, int i, int fd);
int			ft_real_here_doc(t_parsed *lst, t_nod *env, int i, int c);
int			ft_create_here_doc(t_parsed *lst, t_nod *env, int c);
int			ft_mini_check_here_doc(t_parsed *lst);
int			ft_check_here_doc(t_parsed *lst);
void		ft_exit_here_doc_status(t_parsed *lst, int i, t_nod *env);
int			ft_init_fd(int c);
void		ft_clean_here_doc(t_parsed *lst, t_nod *env, char *str, int fd);
////////////////////////////////////////
//////////////Parsing//////////////////
//////////////////////////////////////
void		ft_show_strs(char **strs);
void		ft_close_stdfds(void);
void		ft_true_free(void **ptr);
void		ft_full_free(void **tobefreed);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
ssize_t		ft_count_strs(const char *s, char c);
void		ft_true_split(char const *s, char **strs, char c, ssize_t len);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
ssize_t		ft_count_strs_set(const char *s, char *set);
void		ft_true_split_set(char const *s, char **strs, char *set,
				ssize_t len);
char		**ft_split_set(const char *s, char *set);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_strslen(char **strs);
char		**ft_alloc_strs(int size);
int			ft_isspace(int c);
char		**ft_strsdup(char **src);
int			ft_iscmd(char *str);
int			ft_isheredoc(char *str);
int			ft_isoutfile(char *str);
int			ft_isambiguous(char *str);
int			ft_isinfile(char *str);
int			ft_isredirection(char *str);
int			ft_is_solo(char *str);
int			ft_is_duo(char *str);
void		ft_quotes_focus(char **src, char **trans, int i, int *quotes);
int			ft_check_format_quotes(char *trans, int size);
void		ft_angled_brackets_focus(char **src, char **trans, int i);
char		**ft_get_wrong_angl_brackets(void);
int			ft_check_arg_angl_brackets(char *trans);
int			ft_check_format_angl_brackets(char *src, char *trans);
void		ft_pipes_focus(char **src, char **trans, int i, int *quotes);
int			ft_check_format_pipes(char *trans);
void		ft_replace_spaces(char **trans);
void		ft_rename_ambiguous_tag(char **trans);
void		ft_rename_angl_brackets(char **trans);
void		ft_spaces_focus(char **src, char **trans, int i, int *quotes);
void		ft_var_env_focus(char **src, char **trans, int i, int s_quotes);
void		ft_only_strs_free(char **tobefreed);
void		ft_add_spaces(char **src, char **trans);
int			ft_occurences_counter(char *big, char *little);
void		ft_remove_symbol_var_env(char **src, char **trans, int i);
char		*ft_get_var_env_val(char *src, t_nod *env);
void		ft_disable_var_env(char **src, char **trans);
void		ft_compile_with_val(char **strs, char *var, int i, int j);
void		ft_replace_with_val(char **src, char **trans, char *var, int i);
void		ft_include_var_env(char **src, char **trans, t_nod *env);
void		ft_reveal_ambi_redirect(char **src, char **trans);
void		ft_translation(char **src, char **trans, t_nod *env);
int			ft_check_syntax(char **src, char **trans);
char		*ft_twin_str(char *str1);
t_twins		*ft_init_origin(t_twins *origin, char *str1);
void		ft_free_twins(t_twins *lst);
char		**ft_parallel_split(char **model, char *to_split);
int			ft_sum_strlen(char **strs);
char		**ft_mirror_split(char *src, char **trans);
void		ft_split_on_pipes(t_twins *origin);
t_twins		*ft_init_lst_twins(int size);
void		ft_copy_without_spaces(char **src, char *base, char *alt);
void		ft_split_on_spaces(t_twins *lst, char **src, char **trans);
void		ft_lst_remove_quotes(char **src, char **trans, int i);
void		ft_lst_clean_quotes(t_twins *lst);
void		ft_trim_trans(char **src, char **trans);
void		ft_lst_clean_redirections(t_twins *lst);
void		ft_free_parsed(t_parsed *lst);
t_parsed	*ft_init_lst_parsed(int size);
int			ft_count_cmds(char **trans);
int			ft_count_redirections(char **trans);
int			ft_count_heredocs(char **trans);
void		ft_final_get_cmds(char **cmds, char **src, char **trans);
void		ft_final_get_redir(char **redir, char **src, char **trans);
int			ft_check_if_empty(t_parsed *final);
void		ft_lst_to_final(t_twins *lst, t_parsed *final);
void		ft_show_lst_parsed(t_parsed *lst);
void		ft_label_src_into_trans(char **src, char **trans);
t_parsed	*ft_minishell_parsing(char *str1, t_nod *env);

/*

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
*/
#endif
