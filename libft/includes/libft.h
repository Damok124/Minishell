/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:33:23 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 13:32:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_list
{
	void			*content;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_tools1 {
	char	*tmp;
	char	*line;
	int		n;
	int		i;
}			t_tools1;

typedef struct s_tools2 {
	char	*buff;
	char	*ret;
	int		count;
}			t_tools2;

/////////////////////////
//	PRINT
/////////////////////////
void					ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr_fd_itoa(int n, int fd);
void					ft_putnbr_base_fd(int nbr, char *base, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_show_tab_fd(int len, int *tab, int fd);
void					ft_show_strs_fd(char **strs, int fd);
void					ft_show_strs(char **strs);
/////////////////////////
//	FREE
/////////////////////////
void					ft_full_free_nb(void **tobefreed, int nb);
void					ft_full_free(void **tobefree);
void					ft_only_strs_free(char **tobefreed);
void					ft_true_free(void **ptr);
void					ft_close_stdfds(void);
/////////////////////////
//	CHECK
/////////////////////////
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_strisalnum(char *str);
int						ft_strisalpha(char *str);
int						ft_strisdigit(char *str);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_check_dup_int(int len, int *tab);
int						ft_max(int a, int b);
int						ft_min(int a, int b);
int						ft_check_extension(char *filename, char *extension);
/////////////////////////
//	INITIALIZATION
/////////////////////////
char					**ft_alloc_strs(int size);
void					*ft_calloc(size_t nmemb, size_t size);
void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
char					*ft_strmapi(char const *s, \
	char (*f)(unsigned int, char));
/////////////////////////
//	TRANSFORMATION
/////////////////////////
int						ft_atoi(const char *nptr);
int						ft_atoi_safe(const char *nptr, int *check);
int						ft_atoi_base(const char *nptr, char *base);
int						ft_atoi_base_safe(const char *nptr, int *check, \
	char *base);
long					ft_atol_safe1(const char *nptr, int *check);
long long int			ft_atoll_safe1(const char *nptr, int *check);
unsigned int			ft_atou_safe(const char *nptr, int *check);
unsigned int			ft_atou_base(const char *nptr, char *base);
unsigned int			ft_atou_base_safe(const char *nptr, char *base, \
	int *check);
unsigned long int		ft_atoul_safe(const char *nptr, int *check);
unsigned long long int	ft_atoull_safe(const char *nptr, int *check);
unsigned int			ft_btou(const char *nptr, char *base);
char					*ft_itoa(int n);
char					**ft_split(char const *s, char c);
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strtrim(char const *s1, char const *set);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						*ft_strs_to_tab(int len, char **strs);
int						ft_cap_color(int color);
char					**ft_split_set(const char *s, char *set);
char					**ft_split_at_index(char *str, int i);
/////////////////////////
//	MATHEMATIC
/////////////////////////
int						ft_abs(int x);
int						ft_sqrt(int nb);
size_t					ft_strlen(const char *str);
int						ft_strslen(char **strs);
ssize_t					ft_count_strs(const char *s, char c);
ssize_t					ft_count_strs_set(const char *s, char *set);
int						ft_sum_strlen(char **strs);
/////////////////////////
//	RESEARCH
/////////////////////////
char					*ft_strchr(const char *s, int c);
void					*ft_memchr(const void *s, int c, size_t n);
char					*ft_strnstr(const char *big, const char *little, \
	size_t len);
char					*ft_strrchr(const char *s, int c);
int						ft_strindex(const char *s, int c);
/////////////////////////
//	COPY
/////////////////////////
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
char					*ft_strdup(const char *s);
char					**ft_strsdup(char **src);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
char					*ft_substr(char const *s, unsigned int start, \
	size_t len);
int						*ft_tabdup(int len, int *src, int *dest);
char					*get_next_line(int fd);
/////////////////////////
//	SORTING
/////////////////////////
int						*ft_sort_int_tab(int *tab, int size);
/////////////////////////
//	LISTS
/////////////////////////
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **lst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void*));
void					ft_lstclear(t_list **lst, void (*del)(void*));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *), \
	void (*del)(void *));
t_list					*ft_lst_find_one(t_list *lst, int position);
void					ft_index_intlst(t_list **astack, int *sortedav, int ac);
void					ft_memset_lst(t_list **list, void *content);
t_list					*ft_tab_to_lst(int ac, int *tab);
void					ft_full_free_lst(t_list **list);

#endif
