/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:58:13 by tlarraze          #+#    #+#             */
/*   Updated: 2023/01/16 09:46:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//reproduce echo
void	ft_echo(char **str)
{
	int	i;

	i = 1;
	if (!str[1])
	{
		printf("\n");
		return ;
	}
	if (ft_strncmp(str[0], "echo", 5) == 0 && ft_strncmp(str[1], "-n", 3) == 0)
		ft_echo_n(str);
	else
	{
		while (str[i] != NULL)
		{
			if (str[i + 1] != NULL)
				printf("%s ", str[i]);
			if (str[i + 1] == NULL)
				printf("%s\n", str[i]);
			i++;
		}
	}
}

void	ft_echo_n(char **str)
{
	int	i;

	i = 2;
	while (str[i] != NULL)
	{
		if (str[i + 1] != NULL)
			printf("%s ", str[i]);
		if (str[i + 1] == NULL)
			printf("%s", str[i]);
		i++;
	}
}

void	ft_cd(char **str, t_nod *env)
{
	if (ft_strncmp(str[1], "", ft_strlen(str[1])) == 0 || ft_strncmp(str[1], """", ft_strlen(str[1])) == 34
			|| ft_strncmp(str[1], ".", ft_strlen(".")) == 0)
	{
		chdir(ft_get_env("HOME", env));
		return ;
	}
	if (chdir(str[1]) == -1)
		perror("chdir");
	(void)env;
}

void	ft_pwd(char **str)
{
	char	*path;

	if (str[1])
	{
		printf("pwd: too many arguments\n");
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
			if (ft_strncmp(str[i], tmp->key, ft_strlen(str[i])) == 0)
			{
				tmp_2->next = tmp->next;
				free(tmp->key);
				free(tmp->value);
				free(tmp);
				tmp = env;
			}
			tmp_2 = tmp;
			tmp = tmp->next;
		}
		tmp = env;
		i++;
	}
}
