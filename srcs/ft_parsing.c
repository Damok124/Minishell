/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:01:28 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/17 13:42:41 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <fcntl.h>
#include "minishell.h"

#define SRC 0
#define TRANS 1
#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define SIMPLE 0
#define DOUBLE 1

void	ft_show_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		printf("%s%%\n", strs[i]);
		i++;
	}
}

////////////////////////////////////////////////////////
//TO INCLUDE IN LIBFT

void	ft_close_stdfds(void)
{
	close(STDIN);
	close(STDOUT);
	close(STDERR);
}

ssize_t	ft_count_strs_set(const char *s, char *set)
{
	ssize_t	n;
	ssize_t	i;

	n = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] && ft_strchr(set, s[i]))
			i++;
		if (s[i] && !ft_strchr(set, s[i]))
			n++;
		while (s[i] && !ft_strchr(set, s[i]))
			i++;
	}
	return (n);
}

void	ft_true_split_set(char const *s, char **strs, char *set, ssize_t len)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	a;

	a = 0;
	i = 0;
	j = 0;
	while (s[i] && a < len)
	{
		while (s[i + j] && ft_strchr(set, s[i + j]))
			i++;
		while ((s[i + j] && !ft_strchr(set, s[i + j])))
			j++;
		if (ft_strchr(set, s[i + j]) || s[i + j] == 0)
			strs[a] = ft_substr(s, i, j);
		a++;
		i = i + j;
		j = 0;
	}
}

char	**ft_split_set(const char *s, char *set)
{
	char	**strs;
	ssize_t	len;

	strs = NULL;
	if (s)
	{
		len = ft_count_strs_set(s, set);
		strs = (char **)malloc(sizeof(char *) * (len + 1));
		if (!strs)
			return (NULL);
		strs[len] = NULL;
		ft_true_split_set(s, strs, set, len);
	}
	return (strs);
}

char	*ft_strtrim(char const *s1, char const *set)//update libft
{
	char	*str;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (s1)
	{
		while (s1 && s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1 && s1[i] && ft_strrchr(set, s1[j]))
			j--;
		str = ft_substr(s1, i, (j - i + 1));
		if (str)
			return (str);
	}
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

int	ft_strslen(char **strs)//done go to libft
{
	int	i;

	i = 0;
	while (strs && strs[i])
		i++;
	return (i);
}

char	**ft_alloc_strs(int size)//done go to libft
{
	char **strs;

	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	strs[size] = NULL;
	return (strs);
}

int	ft_isspace(int c)//done go to libft
{
	if ((c > 8 && c < 17) || c == 32)
		return (1);
	else
		return (0);
}

char	**ft_strsdup(char **src)//done go to libft
{
	char	**dest;
	int		i;

	i = 0;
	while (src && src[i])
		i++;
	dest = ft_alloc_strs(i);
	while (--i >= 0)
		dest[i] = ft_strdup(src[i]);
	return (dest);
}

// char **ft_split_at_index(char *str, int i)//optionnal go to libft
// {
// 	char	**final;
// 	char	*first;
// 	char	*last;
//
// 	final = NULL;
// 	if (str)
// 	{
// 		last = ft_strdup(str + i);
// 		str[i] = '\0';
// 		first = ft_strdup(str);
// 		final = (char **)malloc(sizeof(char *) * 3);
// 		if (!final)
// 			return (NULL);
// 		final[0] = first;
// 		final[1] = last;
// 		final[2] = NULL;
// 	}
// 	return (final);
// }

////////////////////////////////////////////////////////////////////////
//TO PARSING.H

int	ft_iscmd(char *str)//done
{
	if (str && str[0] && str[0] == '0')
		return (1);
	return (0);
}

int	ft_isquotes(char c)//done
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	ft_isheredoc(char *str)//done
{
	if (str && str[0])
	{
		if(str[0] == 'H')
			return (1);
	}
	return (0);
}

int	ft_isoutfile(char *str)//done
{
	if (str && str[0])
	{
		if(str[0] == '>')
			return (1);
		if(str[0] == 'A')
			return (2);
	}
	return (0);
}

int	ft_isambiguous(char *str)
{
	if (str && str[0])
	{
		if(str[0] == '?')
			return (1);
	}
	return (0);
}

int	ft_isinfile(char *str)//done
{
	if (str && str[0])
	{
		if(str[0] == '<')
			return (1);
		if(str[0] == 'H')
			return (2);
	}
	return (0);
}

int	ft_isredirection(char *str)//done
{
	if (ft_isinfile(str) || ft_isoutfile(str) || ft_isambiguous(str))
		return (1);
	return (0);
}

int	ft_is_solo(char *str)//done
{
	if (str && str[0] && (str[0] == '<' || str[0] == '>'))
		return (1);
	return (0);
}

int	ft_is_duo(char *str)//done
{
	if (str && str[0] && (str[0] == 'H' || str[0] == 'A'))
		return (1);
	return (0);
}

void	ft_show_duo_strs(char **strs1, char **strs2)//optionnal
{
	int	i;

	i = 0;
	printf(">src   :");
	while (strs1 && strs1[i])
	{
		printf("%s", strs1[i]);
		printf("%%");
		i++;
	}
	i = 0;
	printf("\n");
	printf(">trans :");
	while (strs2 && strs2[i])
	{
		printf("%s", strs2[i]);
		printf("%%");
		i++;
	}
	printf("\n");
}

void	ft_quotes_focus(char **src, char **trans, int i, int *quotes)//done
{
	if (src[0][i] == '\'' && (quotes[DOUBLE] % 2) == 0)
	{
		trans[0][i] = '\'';
		quotes[SIMPLE] += 1;
	}
	else if (src[0][i] == '\"' && (quotes[SIMPLE] % 2) == 0)
	{
		trans[0][i] = '\"';
		quotes[DOUBLE] += 1;
	}
}

int	ft_check_format_quotes(char *trans, int size)
{
	int	i;
	int	quotes[2];

	i = 0;
	quotes[SIMPLE] = 0;
	quotes[DOUBLE] = 0;
	while (i < size && trans && trans[i])
	{
		if (trans[i] == '\'')
			quotes[SIMPLE]++;
		if (trans[i] == '\"')
			quotes[DOUBLE]++;
		i++;
	}
	if ((quotes[SIMPLE] % 2) != 0 || (quotes[DOUBLE] % 2) != 0)
		return (0);
	return (1);
}

void	ft_angled_brackets_focus(char **src, char **trans, int i)
{
	if (ft_strchr("<>", src[0][i]) && ft_check_format_quotes(trans[0], i))
		trans[0][i] = src[0][i];
}

char	**ft_get_wrong_angl_brackets(void)//done
{
	char	**needle;

	needle = (char **)malloc(sizeof(char *) * 5);
	if (!needle)
		return (NULL);
	needle[0] = ft_strdup("<<<");
	needle[1] = ft_strdup(">>>");
	needle[2] = ft_strdup("><");
	needle[3] = ft_strdup("<>");
	needle[4] = NULL;
	return (needle);
}

int	ft_check_arg_angl_brackets(char *trans)
{
	int	i;

	i = 0;
	while (trans && trans[i])
	{
		if (ft_strchr("<>", trans[i]))
		{
			while (trans[i] && ft_strchr("<>", trans[i]))
				i++;
			while (trans[i] && trans[i] == ' ')
				i++;
			if (trans[i] && !ft_strchr("$0\'\"", trans[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_format_angl_brackets(char *src, char *trans)//done
{
	char	**needle;
	int		test;
	int		i;

	i = -1;
	test = 1;
	needle = ft_get_wrong_angl_brackets();
	while (needle[++i] && test)
	{
		if (ft_strnstr(trans, needle[i], ft_strlen(trans)))
			test = 0;
	}
	i = ft_strlen(trans);
	if (i >= 2 && trans[i - 2] && ft_strchr("<>", trans[i - 2]) && test)
		if (ft_strchr("\t\n \"\'#&*./|~<>", src[i - 1]) \
			|| (!ft_isprint(src[i - 1])))
				test = 0;
	if (i >= 1 && trans[i - 1] && ft_strchr("<>", trans[i - 1]) && test)
		test = 0;
	ft_full_free((void **)needle);
	if (test)
		test = ft_check_arg_angl_brackets(trans);
	if (!test)
		return (0);
	return (1);
}

void	ft_pipes_focus(char **src, char **trans, int i, int *quotes)//done
{
	if (src[0][i] == '|' && !(quotes[SIMPLE] % 2) && !(quotes[DOUBLE] % 2))
		trans[0][i] = src[0][i];
}

int	ft_check_format_pipes(char *trans)
{
	int	i;

	i = 0;
	while (trans && trans[i] && ft_isspace(trans[i]))
		i++;
	if (trans [i] && trans[i] == '|')
		return (0);
	while (trans && trans[i])
	{
		if (i && trans[i] && trans[i] == '|')
		{
			i++;
			while (trans[i] && trans[i] == ' ')
				i++;
			if (!trans[i] || (trans[i] && trans[i] == '|'))
				return (0);
			i--;
		}
		i++;
	}
	return (1);
}

void	ft_replace_spaces(char **trans)//done
{
	int	i;

	i = 0;
	while (trans && trans[0] && trans[0][i])
	{
		if (ft_strchr("<>", trans[0][i]) && trans[0][i + 1] == ' ')
		{
			while (trans[0][i + 1] && trans[0][i + 1] == ' ')
			{
				trans[0][i + 1] = '0';
				i++;
			}
			i -= 1;
		}
		i++;
	}
}

void	ft_rename_ambiguous_tag(char **trans)/////////////////////////////
{
	int	i;

	i = 0;
	while (trans && trans[i])
	{
		if (trans[i][0] == '?')
		{
			if (trans[i][2] && trans[i][2] == '>')
				trans[i][1] = 'A';
			trans[i][2] = '\0';
		}
		i++;
	}
}

void	ft_rename_angl_brackets(char **trans)//done
{
	int	i;

	i = 0;
	while (trans && trans[0] && trans[0][i] && trans[0][i + 1])
	{
		if (trans[0][i] == '<' && trans[0][i + 1] == '<')
		{
			trans[0][i] = 'H';
			trans[0][i + 1] = '0';
			i++;
		}
		else if (trans[0][i] == '>' && trans[0][i + 1] == '>')
		{
			trans[0][i] = 'A';
			trans[0][i + 1] = '0';
			i++;
		}
		i++;
	}
}

void	ft_spaces_focus(char **src, char **trans, int i, int *quotes)//done
{
	if (ft_isspace(src[0][i]) && !(quotes[SIMPLE] % 2) && !(quotes[DOUBLE] % 2))
		trans[0][i] = ' ';
}

void	ft_var_env_focus(char **src, char **trans, int i, int s_quotes)//done
{
	int	len;

	len = ft_strlen(src[0]);
	if ((i == 0 && src[0][i] == '$' && len > 1) \
		|| (i != (len - 1) && src[0][i] == '$' && (s_quotes % 2) == 0))
	{
		if (i > 0 && trans[0][i - 1] && trans[0][i - 1] == '$' \
			&& src[0][i] == '$')
			trans[0][i - 1] = '0';
		trans[0][i] = src[0][i];
	}
}

void	ft_only_strs_free(char **tobefreed)//done
{
	int	i;

	i = -1;
	while (tobefreed && tobefreed[++i])
	{
		free(tobefreed[i]);
		tobefreed[i] = NULL;
	}
}

void	ft_add_spaces(char **src, char **trans)//done
{
	int	i;

	i = 0;
	while (trans && trans[0] && trans[0][i])
	{
		if (i > 0 && ft_strchr("<>AH", trans[0][i]) \
			&& !ft_isspace(trans[0][i - 1]))
		{
			src[1] = ft_substr(src[0], 0, i);
			src[2] = ft_strdup(src[0] + i);
			src[3] = ft_strjoin(src[1], " ");
			src[4] = src[0];
			src[0] = ft_strjoin(src[3], src[2]);
			trans[1] = ft_substr(trans[0], 0, i);
			trans[2] = ft_strdup(trans[0] + i);
			trans[3] = ft_strjoin(trans[1], " ");
			trans[4] = trans[0];
			trans[0] = ft_strjoin(trans[3], trans[2]);
			ft_only_strs_free(src + 1);
			ft_only_strs_free(trans + 1);
			i = 0;
		}
		i++;
	}
}

int	ft_occurences_counter(char *big, char *little)//done
{
	int		i;
	int		total;
	int		big_len;
	int		little_len;
	char	*tmp;

	tmp = NULL;
	total = 0;
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	i = 0;
	while (big && big[i] && little && big_len >= little_len)
	{
		tmp = ft_strnstr(big + i, little, little_len);
		if (tmp)
		{
			i += little_len - 1;
			tmp = NULL;
			total++;
		}
		i++;
	}
	return (total);
}

void	ft_remove_symbol_var_env(char **src, char **trans, int i)//done
{
	while (src && src[0] && src[0][i] && ft_isspace(src[0][i]))
		i++;
	while (src && src[0] && src[0][i] && trans && trans[0] && trans[0][i] \
		&& !ft_strchr("<>|$", trans[0][i]) && !ft_isspace(src[0][i]))
	{
		if (trans[0][i] == '\"')
		{
			i++;
			while (trans[0][i] && trans[0][i] != '\"')
				i++;
		}
		else if (trans[0][i] == '\'')
		{
			i++;
			while (trans[0][i] && trans[0][i] != '\'')
				i++;
		}
		i++;
	}
	if (src && src[0] && trans && trans[0] && src[0][i] && trans[0][i] == '$')
		trans[0][i] = '0';
}

void	ft_disable_var_env(char **src, char **trans)//done
{
	char	*tmp;
	int		heredocs;
	int		i;
	int		len;

	i = 0;
	tmp = NULL;
	len = ft_strlen(trans[0]);
	heredocs = ft_occurences_counter(trans[0], "H0");
	while (trans && (len - i) >= 3 && heredocs)
	{
		tmp = ft_strnstr(trans[0] + i, "H0", 2);
		if (tmp)
		{
			tmp = NULL;
			heredocs -= 1;
			if (ft_strnstr(trans[0] + i + 2, "$", len  - (i + 2)))
				ft_remove_symbol_var_env(src, trans, i + 2);
			i++;
		}
		i++;
	}
}

char	*ft_get_var_env_val(char *src, t_nod *env)//done
{
	char	*copy;
	char	*ret;
	int	i;

	i = 0;
	ret = NULL;
	copy = NULL;
	if (src)
	{
		if (src[i] && src[i] == '?')
			copy = ft_strdup("LEC_RV");
		else
		{
			while (src[i] && ft_isalnum(src[i]))
				i++;
			copy = ft_substr(src, 0, i);
		}
		ret = ft_get_env(copy, env);
		ft_true_free((void **)&copy);
		if (ret)
			return (ret);
	}
	return ("");
}

void	ft_compile_with_val(char **strs, char *var, int i, int j)//done
{
	strs[1] = ft_substr(strs[0], 0, i);
	strs[2] = ft_strdup(strs[0] + i + j);
	strs[3] = ft_strjoin(strs[1], var);
	strs[4] = strs[0];
	strs[0] = ft_strjoin(strs[3], strs[2]);
}

void	ft_replace_with_val(char **src, char **trans, char *var, int i)//done
{
	char	*tmp;
	int		j;
	int 	k;

	j = 1;
	k = -1;
	tmp = NULL;
	if (src && src[0] && trans && trans[0] && var)
	{
		while (src[0][i] && src[0][i + j] && ft_isalnum(src[0][i + j]))
			j++;
		if (j == 1 && src[0][i] && src[0][i + j] == '?')
			j = 2;
		ft_compile_with_val(src, var, i, j);
		tmp = ft_strdup(var);
		while (tmp[++k])
			tmp[k] = '0';
		ft_compile_with_val(trans, tmp, i, j);
		ft_true_free((void **)&tmp);
		ft_only_strs_free(src + 1);
		ft_only_strs_free(trans + 1);
	}
}

void	ft_include_var_env(char **src, char **trans, t_nod *env)//done -> to change
{
	int		i;
	char	*var;

	i = 0;
	var = NULL;
	while (src && src[0] && src[0][i] && trans && trans[0] && trans[0][i])
	{
		if (trans[0][i] == '$')
		{
			var = ft_get_var_env_val(src[0] + i + 1, env);
			ft_replace_with_val(src, trans, var, i);
			i = 0;
		}
		else
			i++;
	}
}

void	ft_reveal_ambi_redirect(char **src, char **trans)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (src && trans && src[0] && trans[0] && src[0][i] && trans[0][i])
	{
		if (ft_strchr("<>", trans[0][i]))
			j = 1;
		else if (trans[0][i] == 'A')
			j = 2;
		if (j)
		{
			while (src[0][i + j] && ft_isspace(src[0][i + j]))
				j++;
			while (trans[0][i + j] && ft_strchr("0\"\'", trans[0][i + j]))
				j++;
			if (trans[0][i + j] && trans[0][i + j] == '$')
			{
				trans[0][i + j] = '0';
				trans[0][i] = '?';
			}
			j = 0;
		}
		i++;
	}
}

void	ft_translation(char **src, char **trans, t_nod *env)
{
	// printf("after spaces focus\n");
	// ft_show_duo_strs(src, trans);
	ft_replace_spaces(trans);
	// printf("after replace spaces\n");
	// ft_show_duo_strs(src, trans);
	ft_rename_angl_brackets(trans);
	// printf("after rename angl brackets\n");
	// ft_show_duo_strs(src, trans);
	ft_reveal_ambi_redirect(src, trans);
	// printf("after ambiguous\n");
	// ft_show_duo_strs(src, trans);
	ft_add_spaces(src, trans);
	// printf("after add spaces\n");
	// ft_show_duo_strs(src, trans);
	ft_disable_var_env(src, trans);
	// printf("after disable var env\n");
	// ft_show_duo_strs(src, trans);
	ft_include_var_env(src, trans, env);
	// printf("after include var env\n");
	// ft_show_duo_strs(src, trans);
}

int	ft_check_syntax(char **src, char **trans)////////////////////////////////
{
	if (!ft_check_format_quotes(trans[0], ft_strlen(trans[0])) \
		|| !ft_check_format_angl_brackets(src[0], trans[0]) \
			|| !ft_check_format_pipes(trans[0]))
		return (0);
	return (1);
}

char	*ft_twin_str(char *str1)//done
{
	char *str2;

	str2 = ft_strdup(str1);
	if (str2)
		str2 = ft_memset(str2, '0', ft_strlen(str1));
	else
		str2 = NULL;
	return (str2);
}

t_twins	*ft_init_origin(t_twins *origin, char *str1)//done
{
	origin = (t_twins *)malloc(sizeof(t_twins));
	if (!origin)
		return (NULL);
	origin->src = (char **)malloc(sizeof(char *) * 6);
	if (!origin->src)
	{
		ft_true_free((void **)&origin);
		return (NULL);
	}
	origin->trans = (char **)malloc(sizeof(char *) * 6);
	if (!origin->trans)
	{
		ft_full_free((void **)origin->src);
		ft_true_free((void **)&origin);
		return (NULL);
	}
	origin->src[0] = str1;
	origin->src[1] = NULL;
	origin->src[5] = NULL;
	origin->trans[0] = ft_twin_str(str1);
	origin->trans[1] = NULL;
	origin->trans[5] = NULL;
	origin->next = NULL;
	return (origin);
}

void	ft_free_twins(t_twins *lst)//done
{
	t_twins	*tmp;

	tmp = NULL;
	while (lst)
	{
		if (lst->src)
			ft_full_free((void **)lst->src);
		if (lst->trans)
			ft_full_free((void **)lst->trans);
		tmp = lst;
		lst = lst->next;
		ft_true_free((void **)&tmp);
	}
}

// void	ft_show_twins(t_twins *twins)//optionnal
// {
// 	// ft_show_duo_strs(twins->src, twins->trans);
// }

char	**ft_parallel_split(char **model, char *to_split)//done
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	dest = ft_strsdup(model);
	while (model && model[i])
	{
		ft_strlcpy(dest[i], to_split + j, ft_strlen(dest[i]) + 1);
		j += ft_strlen(dest[i]) + 1;
		i++;
	}
	// ft_show_duo_strs(dest, model);
	return (dest);
}

int	ft_sum_strlen(char **strs)//done go libft
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	j = 0;
	sum = 0;
	while (strs && strs[i])
	{
		while (strs[i][j])
			j++;
		sum += j;
		j = 0;
		i++;
	}
	return (sum);
}

char	**ft_mirror_split(char *src, char **trans)//done
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = NULL;
	if (((ft_strslen(trans) - 1) + ft_sum_strlen(trans)) == (int)ft_strlen(src))
	{
		dest = ft_strsdup(trans);
		while (trans && trans[i])
		{
			while (trans[i][j])
			{
				dest[i][j] = src[j];
				j++;
			}
			src += j + 1;
			j = 0;
			i++;
		}
	}
	return (dest);
}

void	ft_split_on_pipes(t_twins *origin)//done
{

	char *src;
	char *trans;

	src = ft_strdup(origin->src[0]);
	trans = ft_strdup(origin->trans[0]);
	ft_full_free((void **)origin->src);
	ft_full_free((void **)origin->trans);
	origin->trans = ft_split(trans, '|');
	origin->src = ft_mirror_split(src, origin->trans);
	ft_true_free((void **)&src);
	ft_true_free((void **)&trans);
}

t_twins	*ft_init_lst_twins(int size)//done
{
	t_twins	*elem;

	if (size)
	{
		elem = (t_twins *)malloc(sizeof(t_twins));
		if (!elem)
			return (NULL);
		elem->src = NULL;
		elem->trans = NULL;
		elem->next = ft_init_lst_twins(size -1);
		return (elem);
	}
	return (NULL);
}

void	ft_copy_without_spaces(char **src, char *base, char *alt)//done
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (src && src[i] && base && alt)
	{
		while (alt[j] && ft_isspace(alt[j]))
			j++;
		while (alt[j] && !ft_isspace(alt[j]))
			src[i][k++] = base[j++];
		k = 0;
		i++;
	}
}

void	ft_split_on_spaces(t_twins *lst, char **src, char **trans)//done
{
	int	i;

	i = 0;
	while (lst && src && trans && src[i] && trans[i])
	{
		lst->trans = ft_split(trans[i], ' ');
		lst->src = ft_strsdup(lst->trans);
		ft_copy_without_spaces(lst->src, src[i], trans[i]);
		lst = lst->next;
		i++;
	}
}

// void	ft_show_lst_twins(t_twins *lst)//done
// {
// 	int	i;

// 	i = 0;
// 	while (lst)
// 	{
// 		// printf("index lst %d :\n", i);
// 		// ft_show_duo_strs(lst->src, lst->trans);
// 		lst = lst->next;
// 		i++;
// 	}
// }

void	ft_lst_remove_quotes(char **src, char **trans, int i)//done
{
	int	j;

	j = 0;
	while (trans[i][j])
	{
		if (ft_isquotes(trans[i][j]))
		{
			while (trans[i][j])
			{
				trans[i][j] = trans[i][j + 1];
				src[i][j] = src[i][j + 1];
				j++;
			}
			j = -1;
		}
		j++;
	}
}

void	ft_lst_clean_quotes(t_twins *lst)//done
{
	int		i;

	i = 0;
	while (lst)
	{
		while (lst->trans[i])
		{
			ft_lst_remove_quotes(lst->src, lst->trans, i);
			i++;
		}
		i = 0;
		lst = lst->next;
	}
}

void	ft_trim_trans(char **src, char **trans)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src && src[i] && trans && trans[i])
	{
		if (ft_is_duo(trans[i]) || ft_is_solo(trans[i]))
			src[i][0] = ' ';
		if (ft_is_duo(trans[i]))
			src[i][1] = ' ';
		if (src[i][j] && trans[i][j] && trans[i][j] == '?')
		{
			while (src[i][j] && ft_strchr("<>", src[i][j]) && trans[i][j + 1])
			{
				trans[i][j + 1] = src[i][j];
				src[i][j] = ' ';
				j++;
			}
		}
		trans[i][j + 1] = '\0';
		j = 0;
		i++;
	}
	ft_rename_ambiguous_tag(trans);
}

void	ft_lst_clean_redirections(t_twins *lst)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (lst)
	{
		ft_trim_trans(lst->src, lst->trans);
		while (lst->trans && lst->trans[i])
		{
			tmp = lst->src[i];
			lst->src[i] = ft_strtrim(tmp, "\a\b\t\n\v\f\r ");
			ft_true_free((void **)&tmp);
			i++;
		}
		i = 0;
		lst = lst->next;
	}
}

void	ft_free_parsed(t_parsed *lst)//done
{
	t_parsed *tmp;

	while (lst)
	{
		if (lst->cmds)
			ft_full_free((void **)lst->cmds);
		if (lst->redirections)
			ft_full_free((void **)lst->redirections);
		tmp = lst;
		lst = lst->next;
		ft_true_free((void **)&tmp);
	}
}

t_parsed	*ft_init_lst_parsed(int size)//done
{
	t_parsed	*elem;

	if (size)
	{
		elem = (t_parsed *)malloc(sizeof(t_parsed));
		if (!elem)
			return (NULL);
		elem->empty = 1;
		elem->cmds = NULL;
		elem->redirections = NULL;
		elem->cmds_quant = 0;
		elem->redir_quant = 0;
		elem->hdocs_quant = 0;
		elem->next = ft_init_lst_parsed(size -1);
		return (elem);
	}
	return (NULL);
}

int	ft_count_cmds(char **trans)//done
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (trans && trans[i])
	{
		if (ft_iscmd(trans[i]))
			total++;
		i++;
	}
	return (total);
}

int	ft_count_redirections(char **trans)//done
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (trans && trans[i])
	{
		if (ft_isredirection(trans[i]))
			total++;
		i++;
	}
	return (total);
}

int	ft_count_heredocs(char **trans)//done
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (trans && trans[i])
	{
		if (ft_isheredoc(trans[i]))
			total++;
		i++;
	}
	return (total);
}

void	ft_final_get_cmds(char **cmds, char **src, char **trans)//done
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src && trans && src[i] && trans[i])
	{
		if (ft_iscmd(trans[i]))
		{
			cmds[j] = ft_strdup(src[i]);
			j++;
		}
		i++;
	}
}

void	ft_final_get_redir(char **redir, char **src, char **trans)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (src && trans && src[i] && trans[i])
	{
		if (ft_isredirection(trans[i]))
		{
			tmp = ft_strtrim(src[i], "\a\b\t\n\v\f\r ");
			redir[j] = ft_strjoin(trans[i], tmp);
			j++;
			if (tmp)
				ft_true_free((void **)&tmp);
		}
		i++;
	}
}

int	ft_check_if_empty(t_parsed *final)//done
{
	int	test;
	int	i;

	i = 0;
	test = 0;
	if (final->cmds || final->redirections)
	{
		while (final->cmds && final->cmds[i])
		{
			if (final->cmds[i][0])
				test++;
			i++;
		}
		i = 0;
		while (final->redirections && final->redirections[i])
		{
			if (final->redirections[i][1])
				test++;
			i++;
		}
	}
	if (!test)
		return (1);
	return (0);
}

void	ft_lst_to_final(t_twins *lst, t_parsed *final)//done
{
	while (lst && final)
	{
		final->cmds_quant = ft_count_cmds(lst->trans);
		final->redir_quant = ft_count_redirections(lst->trans);
		final->hdocs_quant = ft_count_heredocs(lst->trans);
		if (final->cmds_quant)
		{
			final->cmds = ft_alloc_strs(final->cmds_quant);
			if (final->cmds)
				ft_final_get_cmds(final->cmds, lst->src, lst->trans);
		}
		if (final->redir_quant)
		{
			final->redirections = ft_alloc_strs(final->redir_quant);
			if (final->redirections)
				ft_final_get_redir(final->redirections, lst->src, lst->trans);
		}
		final->empty = ft_check_if_empty(final);
		lst = lst->next;
		final = final->next;
	}
}

void	ft_show_lst_parsed(t_parsed *lst)//done
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("\nindex parsed %d:\n", i);
		printf("cmds  :");
		ft_show_strs(lst->cmds);
		printf("\n");
		printf("redir :");
		ft_show_strs(lst->redirections);
		printf("\n");
		printf("empty :%d; cmds_quant :%d; redir_quant :%d; hdoc_quant :%d\n", lst->empty, lst->cmds_quant, lst->redir_quant, lst->hdocs_quant);
		lst = lst->next;
		i++;
	}
}

void	ft_label_src_into_trans(char **src, char **trans)///////////////////
{
	int	i;
	int	quotes[2];

	i = 0;
	quotes[SIMPLE] = 0;
	quotes[DOUBLE] = 0;
	while (src[0] && src[0][i])
	{
		ft_quotes_focus(src, trans, i, quotes);
		ft_angled_brackets_focus(src, trans, i);
		ft_pipes_focus(src, trans, i, quotes);
		ft_var_env_focus(src, trans, i, quotes[SIMPLE]);
		ft_spaces_focus(src, trans, i, quotes);
		i++;
	}
}

t_parsed	*ft_minishell_parsing(char *str1, t_nod *env)
{
	t_parsed	*final;
	t_twins		*origin;
	t_twins		*lst;

	final = NULL;
	origin = ft_init_origin(NULL, str1);
	lst = NULL;
	// ft_show_twins(origin);
	ft_label_src_into_trans(origin->src, origin->trans);
	// ft_show_twins(origin);
	if (origin->trans && origin->trans[0] && origin->trans[0][0] \
		&& ft_check_syntax(origin->src, origin->trans))
	{
		ft_translation(origin->src, origin->trans, env);
		// ft_show_twins(origin);
		ft_split_on_pipes(origin);
		// ft_show_twins(origin);
		lst = ft_init_lst_twins((int)ft_strslen(origin->trans));
		final = ft_init_lst_parsed((int)ft_strslen(origin->trans));
		ft_split_on_spaces(lst, origin->src, origin->trans);
		// ft_show_lst_twins(lst);
		ft_lst_clean_quotes(lst);
		// ft_show_lst_twins(lst);
		// printf("\nPOWER\n");
		ft_lst_clean_redirections(lst);
		// ft_show_lst_twins(lst);
		ft_lst_to_final(lst, final);
	}
	// ft_show_twins(origin);
	// ft_show_lst_twins(lst);
	//ft_show_lst_parsed(final);
	ft_free_twins(origin);
	ft_free_twins(lst);
	return (final);
}
