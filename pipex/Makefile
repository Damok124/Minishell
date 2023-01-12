# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/11/09 20:08:53 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpipex.a

SRCSDIR = ./srcs/

SRCS = \
${SRCSDIR}ft_cmd_not_found.c \
${SRCSDIR}ft_such_file.c \
${SRCSDIR}ft_close_stdfds.c \
${SRCSDIR}ft_print_cmderr.c \
${SRCSDIR}ft_parse_cmd.c \
${SRCSDIR}ft_double_fullfree.c \
${SRCSDIR}ft_clean_exit.c \
${SRCSDIR}ft_outfile_to_out.c \
${SRCSDIR}ft_append_to_outfile.c \
${SRCSDIR}ft_outfile_permission.c \
${SRCSDIR}ft_init_data.c \
${SRCSDIR}ft_infile_to_in.c \
${SRCSDIR}ft_get_goodpath.c \
${SRCSDIR}ft_get_fullpaths.c \
${SRCSDIR}ft_infile_permission.c \
${SRCSDIR}ft_test_files.c \
${SRCSDIR}ft_get_validpaths.c \
${SRCSDIR}ft_get_paths.c \
${SRCSDIR}ft_clean_connect.c \
${SRCSDIR}ft_check_tmpname.c \
${SRCSDIR}ft_get_tmpname.c \
${SRCSDIR}ft_heredoc_to_file.c \
${SRCSDIR}ft_setup_limiter.c \
${SRCSDIR}ft_heredoc_to_in.c \
${SRCSDIR}ft_parent_hdoc.c \
${SRCSDIR}ft_unlink_and_free.c

HEADERDIR = includes/

HEADER = pipex.h

OBJ = $(SRCS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR) -I../ft_printf/includes/ -I../libft/includes/

all : libft.a libft_printf.a libpipex.a

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libft.a :
	@${MAKE} -sC ../libft/
libft_printf.a :
	@${MAKE} -sC ../ft_printf/
libpipex.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

clean :
	rm -f $(OBJ)
	@${MAKE} clean -sC ../ft_printf/
	@${MAKE} clean -sC ../libft/

fclean : clean
	rm -f $(NAME)
	@${MAKE} fclean -sC ../ft_printf/
	@${MAKE} fclean -sC ../libft/

re : fclean all

.PHONY : all clean fclean re
