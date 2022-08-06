/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:36:59 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/06 16:07:43 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	copy_value_in_rank(t_env *env)
{
	t_node	*cur_node;

	cur_node = env->A->top;
	while (cur_node)
	{
		cur_node->rank = cur_node->value;
		cur_node = cur_node->next;
	}
}

void	sort_values(t_env *env)
{
	t_node	*cur_node;
	t_node	*prev_node;
	int		tmp;

	cur_node = env->A->top->next;
	while (cur_node)
	{
		prev_node = env->A->top;
		while (prev_node != cur_node)
		{
			if (cur_node->value < prev_node->value)
			{
				tmp = cur_node->value;
				cur_node->value = prev_node->value;
				prev_node->value = tmp;
			}
			prev_node = prev_node->next;
		}
		cur_node = cur_node->next;
	}
}

void	find_index(t_stack *A, t_node *cur_node)
{
	t_node	*match_node;
	int	index;

	match_node = A->top;
	index = 1;
	while (cur_node->rank != match_node->value)
	{
		match_node = match_node->next;
		index++;
	}
	cur_node->rank = index;
}


void	convert_numbers_into_index(t_env *env)
{
	t_node	*cur_node;

	cur_node = env->A->top;
	while (cur_node)
	{
		find_index(env->A, cur_node);
		cur_node = cur_node->next;
	}
}

void	fill_copy_rank_in_value(t_env *env)
{
	t_node	*cur_node;

	cur_node = env->A->top;
	copy_value_in_rank(env);
	sort_values(env);
	convert_numbers_into_index(env);
	while (cur_node)
	{
		cur_node->value = cur_node->rank;
		cur_node = cur_node->next;
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
	fill_convert_rank(env);
	return (0);
}*/
