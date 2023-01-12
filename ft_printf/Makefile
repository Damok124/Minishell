# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/11/09 18:49:42 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a

SRCSDIR = ./srcs/

SRCS = $(SRCSDIR)ft_printf.c \
$(SRCSDIR)ft_strprintf.c \
$(SRCSDIR)ft_print_strs.c \
$(SRCSDIR)ft_countnprintf.c

HEADERDIR = includes/

HEADER = ft_printf.h

OBJ = $(SRCS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR)

all : ${NAME}

%.o : %.c
	-@$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libft_printf.a : $(OBJ) $(HEADERDIR)$(HEADER)
	-@ar -rcs $(NAME) $^

clean :
	-@rm -f $(OBJ)

fclean : clean
	-@rm -f $(NAME)
	-@rm -f $(BINARY)

re : fclean all

.PHONY : all clean fclean re
