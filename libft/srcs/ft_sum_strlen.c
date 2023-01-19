/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:13:59 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/19 23:15:14 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sum_strlen(char **strs)
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
