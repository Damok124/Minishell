/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:03:11 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/05 15:10:19 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_msg(t_parsed *lst)
{
	char	*str;
	char	*str_2;

	str = ft_strjoin("Minishell: exit: ", lst->cmds[1]);
	str_2 = ft_strjoin(str, ": numeric argument required\n");
	ft_putstr_fd(str_2, 2);
	free(str);
	free(str_2);
}

int	ft_clean_no_perm(t_core *core, t_nod *env, int check, int id)
{
	if (check == 1 && id == 0)
	{
		close(0);
		ft_clean_end(core->lst[0], core->tmp_stdin, core->p1);
		ft_true_free((void **)&core->id_tab);
		ft_free_env(env);
		exit(1);
	}
	return (0);
}
