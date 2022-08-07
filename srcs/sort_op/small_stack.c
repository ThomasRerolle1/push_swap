/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:35:42 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/07 13:22:40 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_env *env)
{
	t_node	*cur_node;

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
	if (is_sorted(env) == 1)
		return ;
	if (top->value > top->next->value)
	{
		if (top->value > env->A->bot->value)
			ra(env);
		else
			sa(env);
	}
	if (is_sorted(env) == 1)
		return ;
	top = env->A->top;
	if (top->value < top->next->value)
		rra(env);
	sort_three_nums(env);
}

void	sort_five_nums(t_env *env)
{
	if (is_sorted(env))
		return ;
	while (find_two_smallest(env))
		find_push_two_smallest(env);
	if (env->B->top->value < env->B->bot->value)
		sb(env);
	sort_three_nums(env);
	pa(env);
	pa(env);
}
/*
int	main(int argc, char **argv)
{
	t_env	*env;
	char	**av;
	if (argc < 2)
		return (0);
	if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
		av = &argv[1];

	env = create_env();
	if (!parse_argv(env, av))
		return (0);
	fill_copy_rank_in_value(env);
	sort_five_nums(env);
	t_node	*cur_node = env->A->top;
	while (cur_node)
	{
		printf("%i\n", cur_node->value);
		cur_node = cur_node->next;
	}

	env = clear_env(env);
		return (0);
}*/
