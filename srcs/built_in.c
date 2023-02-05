/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:58:13 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/05 15:27:57 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **str, t_nod *env, int i)
{
	char	*str_2;

	if (str && str[1] != NULL && str[2])
	{
		if (i == 0)
			ft_putstr_fd("Minishell: cd: too many arguments\n", 2);
		return (1);
	}
	if (!str[1])
	{
		chdir(ft_get_env("HOME", env));
		return (0);
	}
	if (str && str[1] && chdir(str[1]) == -1)
	{
		if (i == 0)
		{
			str_2 = ft_strjoin(str[1], " : No such file or directory\n");
			ft_putstr_fd(str_2, 2);
			free(str_2);
		}
		return (1);
	}
	return (0);
}

void	ft_pwd(char **str)
{
	char	*path;

	if (str[1])
	{
		path = getcwd(NULL, 6666);
		if (path != NULL)
			printf("%s\n", path);
		return ;
	}
	path = getcwd(NULL, 6666);
	if (path != NULL)
		printf("%s\n", path);
	else
		perror("getcwd");
}

int	ft_unset(char **str, t_nod *env, int do_it)
{
	int		i;
	int		check;
	t_nod	*tmp;
	t_nod	*tmp_2;

	i = 1;
	check = 0;
	tmp = env;
	while (str[i] && do_it == 0)
	{
		check += ft_check_identifier(str[i], 1, 0);
		while (tmp != NULL)
		{
			if (ft_strncmp(str[i], tmp->key, ft_strlen(str[i]) + 1) == 0)
				ft_free_nod_content(tmp, tmp_2, env);
			tmp_2 = tmp;
			tmp = tmp->next;
		}
		tmp = env;
		i++;
	}
	if (check != 0)
		return (1);
	return (0);
}

void	ft_free_nod_content(t_nod *tmp, t_nod *tmp_2, t_nod *env)
{
	tmp_2->next = tmp->next;
	ft_true_free((void **)&tmp->key);
	ft_true_free((void **)&tmp->value);
	ft_true_free((void **)&tmp);
	tmp = env;
}

int	ft_make_nod(t_nod *big_nod[3], char **str, int i, int found)
{
	if (str[1] == NULL)
		return (1);
	if (found == 0)
	{
		big_nod[2] = ft_init_nod(str[i]);
		big_nod[2]->next = NULL;
		big_nod[1]->next = big_nod[2];
	}
	big_nod[1] = big_nod[0];
	return (0);
}
