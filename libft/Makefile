# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2023/01/20 13:31:08 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCSDIR = ./srcs/

SRCS = $(SRCSDIR)ft_memset.c \
$(SRCSDIR)ft_abs.c \
$(SRCSDIR)ft_bzero.c \
$(SRCSDIR)ft_count_strs.c \
$(SRCSDIR)ft_check_extension.c \
$(SRCSDIR)ft_memcpy.c \
$(SRCSDIR)ft_memmove.c \
$(SRCSDIR)ft_memchr.c \
$(SRCSDIR)ft_memcmp.c \
$(SRCSDIR)ft_strlen.c \
$(SRCSDIR)ft_sum_strlen.c \
$(SRCSDIR)ft_isalpha.c \
$(SRCSDIR)ft_isdigit.c \
$(SRCSDIR)ft_isalnum.c \
$(SRCSDIR)ft_strisalpha.c \
$(SRCSDIR)ft_strisdigit.c \
$(SRCSDIR)ft_strisalnum.c \
$(SRCSDIR)ft_isascii.c \
$(SRCSDIR)ft_isprint.c \
$(SRCSDIR)ft_toupper.c \
$(SRCSDIR)ft_tolower.c \
$(SRCSDIR)ft_strchr.c \
$(SRCSDIR)ft_strindex.c \
$(SRCSDIR)ft_strrchr.c \
$(SRCSDIR)ft_strncmp.c \
$(SRCSDIR)ft_strlcpy.c \
$(SRCSDIR)ft_strlcat.c \
$(SRCSDIR)ft_strnstr.c \
$(SRCSDIR)ft_max.c \
$(SRCSDIR)ft_min.c \
$(SRCSDIR)ft_atoi.c \
$(SRCSDIR)ft_atoi_base.c \
$(SRCSDIR)ft_calloc.c \
$(SRCSDIR)ft_strdup.c \
$(SRCSDIR)ft_substr.c \
$(SRCSDIR)ft_strjoin.c \
$(SRCSDIR)ft_strtrim.c \
$(SRCSDIR)ft_split.c \
$(SRCSDIR)ft_itoa.c \
$(SRCSDIR)ft_strmapi.c \
$(SRCSDIR)ft_putchar_fd.c \
$(SRCSDIR)ft_putstr_fd.c \
$(SRCSDIR)ft_putendl_fd.c \
$(SRCSDIR)ft_putnbr_fd.c \
$(SRCSDIR)ft_putnbr_fd_itoa.c \
$(SRCSDIR)ft_putnbr_base_fd.c \
$(SRCSDIR)ft_striteri.c \
$(SRCSDIR)ft_sqrt.c \
$(SRCSDIR)ft_cap_color.c \
$(SRCSDIR)ft_lstnew.c \
$(SRCSDIR)ft_lstadd_front.c \
$(SRCSDIR)ft_lstsize.c \
$(SRCSDIR)ft_lstlast.c \
$(SRCSDIR)ft_lstadd_back.c \
$(SRCSDIR)ft_lstdelone.c \
$(SRCSDIR)ft_lstclear.c \
$(SRCSDIR)ft_lstiter.c \
$(SRCSDIR)ft_lstmap.c \
$(SRCSDIR)ft_full_free.c \
$(SRCSDIR)ft_full_free_nb.c \
$(SRCSDIR)ft_true_free.c \
$(SRCSDIR)ft_atoi_safe.c \
$(SRCSDIR)ft_atoi_base_safe.c \
$(SRCSDIR)ft_atol_safe.c \
$(SRCSDIR)ft_atoll_safe.c \
$(SRCSDIR)ft_atou_safe.c \
$(SRCSDIR)ft_btou.c \
$(SRCSDIR)ft_atou_base.c \
$(SRCSDIR)ft_atou_base_safe.c \
$(SRCSDIR)ft_atoul_safe.c \
$(SRCSDIR)ft_atoull_safe.c \
$(SRCSDIR)ft_check_dup_int.c \
$(SRCSDIR)ft_tabdup.c \
$(SRCSDIR)ft_sort_int_tab.c \
$(SRCSDIR)ft_show_tab_fd.c \
$(SRCSDIR)ft_show_strs_fd.c \
$(SRCSDIR)ft_show_strs.c \
$(SRCSDIR)ft_strs_to_tab.c \
$(SRCSDIR)ft_tab_to_lst.c \
$(SRCSDIR)ft_memset_lst.c \
$(SRCSDIR)ft_only_strs_free.c \
$(SRCSDIR)ft_full_free_lst.c \
$(SRCSDIR)ft_index_intlst.c \
$(SRCSDIR)ft_lst_find_one.c \
$(SRCSDIR)ft_close_stdfds.c \
$(SRCSDIR)ft_count_strs_set.c \
$(SRCSDIR)ft_split_set.c \
$(SRCSDIR)ft_strslen.c \
$(SRCSDIR)ft_alloc_strs.c \
$(SRCSDIR)ft_isspace.c \
$(SRCSDIR)ft_strsdup.c \
$(SRCSDIR)ft_split_at_index.c \
$(SRCSDIR)get_next_line.c

HEADERDIR = includes/

HEADER = libft.h

OBJ = $(SRCS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR)

all : ${NAME}

%.o : %.c
	-@$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libft.a : $(OBJ) $(HEADERDIR)$(HEADER)
	-@ar -rcs $(NAME) $^

clean :
	-@rm -f $(OBJ)

fclean : clean
	-@rm -f $(NAME)
	-@rm -f $(BINARY)

re : fclean all

.PHONY : all clean fclean re
