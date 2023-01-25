# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2023/01/25 17:36:15 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE=\033[4;96m

BINARY = minishell

NAME = libminishell.a

LIBFT = libft/libft.a

LIBFT_PRINTF = ft_printf/libft_printf.a

SRCSDIR = ./srcs/

SRCS = \
${SRCSDIR}env.c \
${SRCSDIR}built_in.c \
${SRCSDIR}built_in_2.c \
${SRCSDIR}built_in_3.c \
${SRCSDIR}ft_execute_cmd.c \
${SRCSDIR}ft_init_fork.c \
${SRCSDIR}ft_echo.c \
${SRCSDIR}ft_check_execute_and_utils.c \
${SRCSDIR}ft_exit.c \
${SRCSDIR}ft_id_tab.c \
${SRCSDIR}ft_here_doc_utils.c \
${SRCSDIR}ft_export.c \
${SRCSDIR}ft_clean_pipex_2.c \
${SRCSDIR}ft_execute.c \
${SRCSDIR}ft_clean_connect.c \
${SRCSDIR}ft_infile_outfile.c \
${SRCSDIR}ft_here_doc.c \
${SRCSDIR}ft_here_doc_2.c \
${SRCSDIR}ft_outfile.c \
${SRCSDIR}ft_infile.c \
${SRCSDIR}/parsing/ft_replace_src_redir_symbols.c \
${SRCSDIR}/parsing/ft_begin_strtrim.c \
${SRCSDIR}/parsing/ft_redir_to_clean.c \
${SRCSDIR}/parsing/ft_clean_redir.c \
${SRCSDIR}/parsing/ft_iscmd.c \
${SRCSDIR}/parsing/ft_isquotes.c \
${SRCSDIR}/parsing/ft_isheredoc.c \
${SRCSDIR}/parsing/ft_isoutfile.c \
${SRCSDIR}/parsing/ft_isambiguous.c \
${SRCSDIR}/parsing/ft_isinfile.c \
${SRCSDIR}/parsing/ft_isredirection.c \
${SRCSDIR}/parsing/ft_is_solo.c \
${SRCSDIR}/parsing/ft_is_duo.c \
${SRCSDIR}/parsing/ft_show_duo_strs.c \
${SRCSDIR}/parsing/ft_quotes_focus.c \
${SRCSDIR}/parsing/ft_check_format_quotes.c \
${SRCSDIR}/parsing/ft_angled_brackets_focus.c \
${SRCSDIR}/parsing/ft_get_wrong_angl_brackets.c \
${SRCSDIR}/parsing/ft_check_arg_angl_brackets.c \
${SRCSDIR}/parsing/ft_check_format_angl_brackets.c \
${SRCSDIR}/parsing/ft_pipes_focus.c \
${SRCSDIR}/parsing/ft_check_format_pipes.c \
${SRCSDIR}/parsing/ft_replace_spaces.c \
${SRCSDIR}/parsing/ft_rename_ambiguous_tag.c \
${SRCSDIR}/parsing/ft_rename_angl_brackets.c \
${SRCSDIR}/parsing/ft_spaces_focus.c \
${SRCSDIR}/parsing/ft_var_env_focus.c \
${SRCSDIR}/parsing/ft_add_spaces.c \
${SRCSDIR}/parsing/ft_occurences_counter.c \
${SRCSDIR}/parsing/ft_remove_symbol_var_env.c \
${SRCSDIR}/parsing/ft_disable_var_env.c \
${SRCSDIR}/parsing/ft_get_var_env_val.c \
${SRCSDIR}/parsing/ft_compile_with_val.c \
${SRCSDIR}/parsing/ft_replace_with_val.c \
${SRCSDIR}/parsing/ft_include_var_env.c \
${SRCSDIR}/parsing/ft_reveal_ambi_redirect.c \
${SRCSDIR}/parsing/ft_translation.c \
${SRCSDIR}/parsing/ft_check_syntax.c \
${SRCSDIR}/parsing/ft_twin_str.c \
${SRCSDIR}/parsing/ft_init_origin.c \
${SRCSDIR}/parsing/ft_free_twins.c \
${SRCSDIR}/parsing/ft_show_twins.c \
${SRCSDIR}/parsing/ft_parallel_split.c \
${SRCSDIR}/parsing/ft_mirror_split.c \
${SRCSDIR}/parsing/ft_split_on_pipes.c \
${SRCSDIR}/parsing/ft_init_lst_twins.c \
${SRCSDIR}/parsing/ft_copy_without_spaces.c \
${SRCSDIR}/parsing/ft_split_on_spaces.c \
${SRCSDIR}/parsing/ft_show_lst_twins.c \
${SRCSDIR}/parsing/ft_lst_remove_quotes.c \
${SRCSDIR}/parsing/ft_lst_clean_quotes.c \
${SRCSDIR}/parsing/ft_trans_to_symbol.c \
${SRCSDIR}/parsing/ft_lst_trans_symbol.c \
${SRCSDIR}/parsing/ft_free_parsed.c \
${SRCSDIR}/parsing/ft_init_lst_parsed.c \
${SRCSDIR}/parsing/ft_count_cmds.c \
${SRCSDIR}/parsing/ft_count_redirections.c \
${SRCSDIR}/parsing/ft_count_heredocs.c \
${SRCSDIR}/parsing/ft_final_get_cmds.c \
${SRCSDIR}/parsing/ft_final_get_redir.c \
${SRCSDIR}/parsing/ft_check_if_empty.c \
${SRCSDIR}/parsing/ft_lst_to_final.c \
${SRCSDIR}/parsing/ft_show_lst_parsed.c \
${SRCSDIR}/parsing/ft_label_src_into_trans.c \
${SRCSDIR}/parsing/ft_minishell_parsing.c

HEADERDIR = includes/

HEADER = minishell.h

OBJ = $(SRCS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

LFLAGS = -L/usr/local/lib -I/usr/local/include -lreadline

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/

all : ${LIBFT} ${LIBFT_PRINTF} libminishell.a $(BINARY)

$(BINARY):
	@$(CC) $(FLAGS) main.c $(IFLAG) -L. -lminishell -L./libft -lft \
	-L./ft_printf -lft_printf -o $(BINARY) $(LFLAGS)
	@echo "${BLUE}***Compilation_Complete***"

%.o : %.c
	@$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

${NAME} : $(OBJ) $(HEADERDIR)$(HEADER)
	@ar -rcs $(NAME) $^

${LIBFT} :
	@${MAKE} -sC libft/

${LIBFT_PRINTF} :
	@${MAKE} -sC ft_printf/

clean :
	@rm -f $(OBJ)
	@${MAKE} clean -sC libft/
	@${MAKE} clean -sC ft_printf/

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BINARY)
	@${MAKE} fclean -sC libft/
	@${MAKE} fclean -sC ft_printf/

re : fclean all

.PHONY : all clean fclean re
