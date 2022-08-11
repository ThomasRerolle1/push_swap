/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:02:43 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/11 15:32:41 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*create_assign_connect_node(t_node *cur_node, char *str);

int	iter_node(t_stack *a)
{
	t_node	*cur_node;
	int		i;

	i = 0;
	if (!a)
		return (i);
	cur_node = a->top;
	while (cur_node)
	{
		i++;
		cur_node = cur_node->next;
	}
	return (i);
}

int	parse_argv(t_env *env, char **argv)
{
	int		i;
	t_node	*cur_node;
	t_node	*next_node;

	i = 0;
	cur_node = NULL;
	next_node = NULL;
	while (argv[i])
		if (!check_is_num(argv[i++]))
			return (0);
	while (*argv)
	{
		if (!check_int(*argv))
			return (0);
		next_node = create_assign_connect_node(cur_node, *argv);
		cur_node = next_node;
		argv++;
		env->a = link_nodes_to_stack(env->a, next_node);
	}
	if (!check_dup(env))
		return (0);
	env->a->size = iter_node(env->a);
	return (1);
}
/*
int	main(int argc, char **argv)
{
	t_env	*env;
	t_node	*cur_node;
	if (argc < 2)
		return (0);
	env = create_env();
	if (!parse_argv(env, &argv[1]))
	{
		printf("fail to parse, input error\n");
	}
	else
	{
		printf("succesfully parse\n");
	}
	cur_node = env->a->top;
	while (cur_node)
	{
		printf("%d\n", cur_node->value);
		cur_node = cur_node->next;
	}
	env = clear_env(env);
	return (0);
}*/
