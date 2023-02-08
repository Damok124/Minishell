/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:11:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/08 18:46:13 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
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
	int				declare;
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

typedef struct s_core
{
	t_parsed		*lst[2];
	t_nod			*env;
	int				p1[2];
	int				tmp_stdin;
	int				*id_tab;
}					t_core;

typedef struct s_twins
{
	char			**src;
	char			**trans;
	struct s_twins	*next;
}			t_twins;

/////////////////////////
//	DEFINES
/////////////////////////

# define SRC 0
# define TRANS 1
# define SIMPLE 0
# define DOUBLE 1
# define READ_END 0
# define WRITE_END 1
# define HEREDOC ".tmp_here_doc_tmpfile_touch_it_and_you_will_die_!"
# define HRM "Minishell: warning: delimited by end-of-file (wanted '%s')\n"

/////////////////////////
//	PROMPT
/////////////////////////

char		*ft_get_env(char *str, t_nod *env);

/////////////////////////
//	FT_ECHO
/////////////////////////
void		ft_echo(char **str);
void		ft_echo_n(char **str);
int			ft_check_echo_n(char *str);
/////////////////////////
//	FT_EXPORT
/////////////////////////
int			ft_export(char **str, t_nod *env, int doo);
void		ft_show_declare(t_nod *env);
int			ft_make_nod(t_nod *big_nod[3], char **str, int i, int found);
void		ft_add_basic_plus_nod(t_nod *nod, char *str, int i);
void		ft_add_mini_nod_basic(t_nod *nod, char *str, int i);
int			ft_check_identifier(char *str, int type, int do_it);
int			ft_check_first_half(char *str, int type);
void		ft_export_unset_error_message(char *str, int type);
int			ft_check_number_export(char c);
void		ft_add_to_export_no_value(t_nod *nod, char *str);
int			ft_search_delimiter(char *str);
void		ft_add_to_env_no_value(t_nod *nod, char *str);
void		ft_add_basic(t_nod *nod, char *str);
void		ft_add_basic_and_plus(t_nod *nod, char *str);
int			ft_check_middle_identifier(char *str, int type, int i);
void		ft_choose_export(t_nod *big_nod[3], int do_it, int check,
				char *str);
void		ft_add_basic_nod(t_nod *nod, char *str, int i);
t_nod		*ft_free_nod_content(t_nod *tmp, t_nod *tmp_2, t_nod *env);

/////////////////////////
//	FT_CD
/////////////////////////
int			ft_cd(char **str, t_nod *env, int i);
int			ft_chdir_home(char *str, t_nod *env, int i);
void		ft_call_chdir(t_nod *tmp, t_nod *env);
int			ft_chdir(char *str, t_nod *env);

////////////////////////////////////////////////////////////////
void		ft_pwd(char **str);
int			ft_unset(char **str, t_nod *env, int do_it);
void		ft_env(t_nod *env);
t_nod		*ft_init_lst(char **env);
t_nod		*ft_init_nod(char *str);
char		**ft_env_to_tab(t_nod *nod, t_parsed *lst[2]);
int			ft_call_export(t_parsed *lst[2], t_nod *env, int i);

/////////////////////////
//	FT_EXIT
/////////////////////////
int			ft_exit(t_core *core, int print_check, t_nod *env, int *tab);
int			ft_exit_2(t_core *core, int print_check, t_nod *env, int *tab);
void		ft_check_exit_arg(t_core *core, int print_check, t_nod *env,
				int *tab);
int			ft_check_num(char *str);
long int	ft_long_atoi(const char *nptr);
void		ft_error_msg(t_parsed *lst);
void		ft_print_exit_error(t_core *core, int print_check, int *check);
////////////////////////////////////////////////////////////////
int			ft_check_unset_export(t_core *core, t_nod *env, int i);
void		ft_fuse_end_env(t_nod *first, char **strs);
void		ft_free_env(t_nod *env);
void		ft_file_destroy(int i);
void		ft_return_value(int value, t_nod *env, int *i);
int			ft_check_file_error(t_parsed *lst, int i);
/////////////////////////
//	ID_TAB
/////////////////////////

int			*ft_make_id_tab(t_parsed *lst);
void		ft_wait_id(t_nod *env, int *tab);
int			ft_get_id_tab_index(int *tab);

/////////////////////////
//	EXEC
/////////////////////////
t_core		*ft_init_execute(t_parsed *lst, t_core *core, int *i, int *fd);
int			ft_init_fork(int id, int tmp_stdin, int check);
void		ft_pipe(int p1[2], t_parsed *lst[2]);
void		ft_execute_core(t_core *core, t_nod *env, char *str);
int			ft_execute_end(t_parsed *lst[2], int tmp_stdin, int i);
int			ft_check_redir(t_parsed *lst[2], t_nod *env, int tmp_stdin,
				int p1[2]);
int			ft_check_perm(char *str);
int			ft_clean_no_perm(t_core *core, t_nod *env, int check, int id);
void		ft_print_error_double(char *str, char *str2);
int			ft_check(t_parsed *lst[2], t_nod *env, int tmp_stdin, int p1[2]);
int			ft_check_exit_null_cmd(t_parsed *lst[2], int tmp_stdin, int p1[2]);
int			ft_cmd_not_found_print(t_parsed *lst);
void		ft_clean_end(t_parsed *lst, int tmp_stdin, int p1[2]);
void		ft_clean_exit(t_parsed *lst, t_nod *env, int p1[2]);
void		ft_clean_pipex_2(t_parsed *lst[2], t_nod *env, char **tab,
				char *path);
void		ft_while(t_nod *env_nod);
void		ft_execute(char *str, t_nod *env);
void		ft_execute_cmd(t_core *core, t_nod *env, int *id_tab,
				int p1[2]);
char		*ft_access(t_parsed *lst, char *str, char *value);
int			ft_call_print_error(t_parsed *lst, int i);
int			ft_check_dir_file(t_parsed *lst, char *str);
int			ft_big_check_access( t_parsed *lst, char *str, int type);
void		ft_free_double(char **str, char *str2);
char		*ft_check_access(char **env, char **path, char *str);
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
int			ft_init_pipe(t_parsed *lst, int p1[2], int id, int i);
int			ft_do_need_pipe(t_parsed *lst, int j);
void		ft_close(int a, int b, int c, int d);
int			ft_search_built_in(t_parsed *lst);
int			ft_call_built_in(t_core *core, t_nod *env, int *tab);
void		ft_clean_connect(int std, int toconnect, int toclose);
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
int			ft_error_heredoc(t_parsed *lst, t_nod *env, int *i);
void		ft_clean_here_doc(t_parsed *lst, t_nod *env, char *str, int fd);

////////////////////////////////////////
//////////////Parsing//////////////////
//////////////////////////////////////

/////////////////////////
//	CHECKERS
/////////////////////////
int			ft_iscmd(char *str);
int			ft_isquotes(char c);
int			ft_isheredoc(char *str);
int			ft_isoutfile(char *str);
int			ft_isambiguous(char *str);
int			ft_isinfile(char *str);
int			ft_isredirection(char *str);
int			ft_is_solo(char *str);
int			ft_is_duo(char *str);
int			ft_check_syntax(char **src, char **trans);
int			ft_check_if_empty(t_parsed *final);

/////////////////////////
//	PRINTERS
/////////////////////////
void		ft_show_duo_strs(char **strs1, char **strs2);
void		ft_show_twins(t_twins *twins);
void		ft_show_lst_twins(t_twins *lst);
void		ft_show_lst_parsed(t_parsed *lst);

/////////////////////////
//	COUNTERS
/////////////////////////
int			ft_count_cmds(char **trans);
int			ft_count_redirections(char **trans);
int			ft_count_heredocs(char **trans);
int			ft_occurences_counter(char *big, char *little);

/////////////////////////
//	QUOTES MANAGERS
/////////////////////////
void		ft_quotes_focus(char **src, char **trans, int i, int *quotes);
int			ft_check_format_quotes(char *trans, int size);
void		ft_lst_remove_quotes(char **src, char **trans, int i);
void		ft_lst_clean_quotes(t_twins *lst);

/////////////////////////
//	ANGLED BRACKETS MANAGERS
/////////////////////////
void		ft_angled_brackets_focus(char **src, char **trans, int i);
char		**ft_get_wrong_angl_brackets(void);
int			ft_check_arg_angl_brackets(char *trans);
int			ft_check_format_angl_brackets(char *src, char *trans);
void		ft_rename_angl_brackets(char **trans);

/////////////////////////
//	PIPES MANAGERS
/////////////////////////
void		ft_pipes_focus(char **src, char **trans, int i, int *quotes);
int			ft_check_format_pipes(char *trans);

/////////////////////////
//	SPACES MANAGERS
/////////////////////////
void		ft_replace_spaces(char **trans);
void		ft_spaces_focus(char **src, char **trans, int i, int *quotes);
void		ft_add_spaces(char **src, char **trans);
void		ft_copy_without_spaces(char **src, char *base, char *alt);
void		ft_split_on_spaces(t_twins *lst, char **src, char **trans);

/////////////////////////
//	VAR ENV MANAGERS
/////////////////////////
void		ft_rename_ambiguous_tag(char **trans);
void		ft_var_env_focus(char **src, char **trans, int i, int s_quotes);
void		ft_remove_symbol_var_env(char **src, char **trans, int i);
void		ft_disable_var_env(char **src, char **trans);
char		*ft_get_var_env_val(char *src, t_nod *env);
void		ft_include_var_env(char **src, char **trans, t_nod *env);
void		ft_compile_with_val(char **strs, char *var, int i, int j);
void		ft_replace_with_val(char **src, char **trans, char *var, int i);
void		ft_reveal_ambi_redirect(char **src, char **trans);
void		ft_disable_unnamed_var_env(char **trans);
void		ft_disable_no_name_var_env(char **src, char **trans);

/////////////////////////
//	INITIALIZERS
/////////////////////////
t_twins		*ft_init_origin(t_twins *origin, char *str1);
t_twins		*ft_init_lst_twins(int size);
t_parsed	*ft_init_lst_parsed(int size);

/////////////////////////
//	MEMORY MANAGERS
/////////////////////////
void		ft_free_twins(t_twins *lst);
void		ft_free_parsed(t_parsed *lst);

/////////////////////////
//	TRANSFORMERS
/////////////////////////
void		ft_split_on_pipes(t_twins *origin);
char		*ft_twin_str(char *str1);
char		**ft_parallel_split(char **model, char *to_split);
void		ft_translation(char **src, char **trans, t_nod *env);
char		**ft_mirror_split(char *src, char **trans);
void		ft_trans_to_symbol(char **src, char **trans);
void		ft_lst_trans_symbol(t_twins *lst);
void		ft_clean_redir(char **srcs, int target, char *set);
void		ft_redir_to_clean(char **src, char **trans);
char		*ft_begin_strtrim(char const *s1, char const *set);
void		ft_replace_src_redir_symbols(char **src, char **trans, int i);
void		ft_lst_nullbyte_chase(t_twins *lst);

/////////////////////////
//	CORE
/////////////////////////
void		ft_final_get_cmds(char **cmds, char **src, char **trans);
void		ft_final_get_redir(char **redir, char **src, char **trans);
void		ft_lst_to_final(t_twins *lst, t_parsed *final);
void		ft_label_src_into_trans(char **src, char **trans);
t_parsed	*ft_minishell_parsing(char *str1, t_nod *env);

#endif
