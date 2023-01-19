# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2023/01/19 22:47:57 by zharzi           ###   ########.fr        #
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
${SRCSDIR}ft_parsing.c \
${SRCSDIR}ft_pipex.c \
${SRCSDIR}ft_echo.c \
${SRCSDIR}ft_exit.c \
${SRCSDIR}ft_export.c \
${SRCSDIR}ft_execute.c \
${SRCSDIR}ft_clean_connect.c \
${SRCSDIR}ft_infile_outfile.c \
${SRCSDIR}ft_here_doc.c \
${SRCSDIR}ft_here_doc_2.c \
${SRCSDIR}ft_outfile.c \
${SRCSDIR}ft_infile.c \

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
