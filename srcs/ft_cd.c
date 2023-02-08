/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:57:13 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/07 18:34:01 by tlarraze         ###   ########.fr       */
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
		i = ft_chdir_home(NULL, env, i);
		return (i);
	}
	if (str && str[1] && ft_chdir(str[1], env) == -1)
	{
		if (i == 0)
		{
			str_2 = ft_strjoin(str[1], " : No such file or directory\n");
			ft_putstr_fd(str_2, 2);
			ft_true_free((void **)&str_2);
		}
		return (1);
	}
	return (0);
}

int	ft_chdir(char *str, t_nod *env)
{
	t_nod	*tmp;
	char	*pwd;
	int		i;

	tmp = env;
	while (tmp && ft_strncmp(tmp->key, "OLDPWD", 7) != 0)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		i = chdir(str);
		return (i);
	}
	pwd = getcwd(NULL, 666);
	i = chdir(str);
	if (i == 0)
	{
		ft_true_free((void **)&tmp->value);
		tmp->value = NULL;
		tmp->value = pwd;
	}
	else
		ft_true_free((void **)&pwd);
	return (i);
}

int	ft_chdir_home(char *str, t_nod *env, int i)
{
	t_nod	*tmp;

	tmp = env;
	if (str == NULL)
	{
		while (tmp && ft_strncmp(tmp->key, "HOME", 5) != 0)
			tmp = tmp->next;
		if (tmp == NULL)
		{
			if (i == 0)
				ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (1);
		}
		else if (tmp != NULL)
		{
			tmp = env;
			while (tmp && ft_strncmp(tmp->key, "OLDPWD", 7) == 0)
				tmp = tmp->next;
			if (tmp != NULL)
				ft_call_chdir(tmp, env);
		}
	}
	return (0);
}

void	ft_call_chdir(t_nod *tmp, t_nod *env)
{
	ft_true_free((void **)&tmp->value);
	tmp->value = NULL;
	tmp->value = getcwd(tmp->value, 666);
	chdir(ft_get_env("HOME", env));
}
