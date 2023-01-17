# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2023/01/17 17:43:18 by tlarraze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE=\033[4;96m

NAME = libminishell.a

BINARY = minishell

SRCSDIR = ./srcs/

SRCS = \
${SRCSDIR}env.c \
${SRCSDIR}built_in.c \
${SRCSDIR}built_in_2.c \
${SRCSDIR}built_in_3.c \
${SRCSDIR}ft_parsing.c \
${SRCSDIR}ft_pipex.c \
${SRCSDIR}ft_echo.c \
${SRCSDIR}ft_execute.c \
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

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/ -Ipipex/includes/

all : libft.a libft_printf.a libpipex.a libminishell.a $(BINARY)

$(BINARY):
	@$(CC) $(FLAGS) main.c $(IFLAG) -L. -lminishell -L./pipex -lpipex \
		-L./libft -lft -L./ft_printf -lft_printf -o $(BINARY) $(LFLAGS)
	@echo "${BLUE}***Compilation_Complete***"

%.o : %.c
	@$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libminishell.a : $(OBJ) $(HEADERDIR)$(HEADER)
	@ar -rcs $(NAME) $^

libft.a :
	@${MAKE} -sC libft/

libft_printf.a :
	@${MAKE} -sC ft_printf/

libpipex.a :
	@${MAKE} -sC pipex/

clean :
	@rm -f $(OBJ)
	@${MAKE} clean -sC libft/
	@${MAKE} clean -sC ft_printf/
	@${MAKE} clean -sC pipex/

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BINARY)
	@${MAKE} fclean -sC libft/
	@${MAKE} fclean -sC ft_printf/
	@${MAKE} fclean -sC pipex/

re : fclean all

bre : fclean bonus

.PHONY : all bonus clean fclean re bre
