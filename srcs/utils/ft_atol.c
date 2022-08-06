/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:57:29 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/03 11:28:30 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*int	is_space(char c)
{
	if (c == ' ' ^ c == '\t' ^ c == '\v' ^ c == '\f' ^ c == '\r' ^ c == '\n')
		return (1);
	return (0);
}*/

long	ft_atol(char *str)
{
	long	i;
	long	res;
	long	minus;

	i = 0;
	res = 0;
	minus = 1;
	while (is_space(str[i] == 1))
			i++;
	if (str[i] == '+' ^ str[i] == '-')
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * minus);
}
