/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:58:13 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/26 18:59:56 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **str, t_nod *env, int i)
{
	char	*str_2;

	if (str[2])
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
	if (chdir(str[1]) == -1)
	{
		if (i == 0)
		{
			str_2 = ft_strjoin(str[1]," : No such file or directory\n");
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

void	ft_unset(char **str, t_nod *env)
{
	int		i;
	t_nod	*tmp;
	t_nod	*tmp_2;

	i = 1;
	tmp = env;
	while (str[i])
	{
		while (tmp != NULL)
		{
			if (ft_strncmp(str[i], tmp->key, ft_strlen(str[i]) + 1) == 0)
			{
				tmp_2->next = tmp->next;
				ft_true_free((void **)&tmp->key);
				ft_true_free((void **)&tmp->value);
				ft_true_free((void **)&tmp);
				tmp = env;
			}
			tmp_2 = tmp;
			tmp = tmp->next;
		}
		tmp = env;
		i++;
	}
}
