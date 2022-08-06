/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:35:42 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/06 16:38:36 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_env *env)
{
	t_node	*cur_node;

	if (env->B->size != 0)
		return (0);
	cur_node = env->A->top;
	while (cur_node->next)
	{
		if (cur_node->value > cur_node->next->value)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}

void	sort_three_nums(t_env *env)
{
	t_node	*top;

	top = env->A->top;
	if (is_sorted(env))
		return ;
	if (top->value > top->next->value)
	{
		if (top->value > env->A->bot->value)
			ra(env);
		else
			sa(env);
	}
	top = env->A->top;
	if (top->value < top->next->value)
		rra(env);
	sort_three_nums(env);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		return (0);
	env = create_env();
	if (!parse_argv(env, &argv[1]))
		return (0);
	fill_copy_rank_in_value(env);
	sort_three_nums(env);
	env = clear_env(env);
	return (0);
}
