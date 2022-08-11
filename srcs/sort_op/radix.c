/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:24:13 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/11 15:21:43 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	radix(t_env *env)
{
	int	cur_bit;
	int	index_max;
	int	cur_index;

	cur_bit = 0;
	index_max = env->a->size;
	while (!is_sorted(env))
	{
		cur_index = 1;
		while (cur_index <= index_max)
		{
			if (env->a->top->value & (1 << cur_bit))
				ra(env);
			else
				pb(env);
			cur_index++;
		}
		while (env->b->top)
			pa(env);
		cur_bit++;
	}
}

/*
int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		return (0);
	env = create_env();
	if (!parse_argv(env, &argv[1]))
		return (0);
	radix(env);
	t_node	*cur_node = env->a->top;
	while (cur_node)
	{
		printf("%i\n", cur_node->value);
		cur_node = cur_node->next;
	}
	env = clear_env(env);
}*/
