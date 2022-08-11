/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:22:44 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/11 15:17:21 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_int(char *str)
{
	long	res;

	res = ft_atol(str);
	if (res < INT_MIN || INT_MAX < res)
		return (0);
	return (1);
}

int	check_dup(t_env *env)
{
	t_node	*cur_node;
	t_node	*node_to_test;

	cur_node = env->a->top;
	while (cur_node)
	{
		node_to_test = cur_node->next;
		while (node_to_test)
		{
			if (cur_node->value == node_to_test->value)
				return (0);
			node_to_test = node_to_test->next;
		}
		cur_node = cur_node->next;
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	int i = 1;

	if (argc < 2)
		return (0);
	while (argv[i])
	{
		if (!check_is_num(argv[i]))
			printf("not number\n");
		else
			printf("num\n");
		i++;
	}
	if (!check_dup(env))
	return (0);
}*/
