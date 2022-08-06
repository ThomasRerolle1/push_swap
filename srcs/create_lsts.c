/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lsts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 07:49:50 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/06 14:36:14 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*create_node(void)
{
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	if (!ptr)
		return (NULL);
	ptr->next = NULL;
	ptr->prev = NULL;
	ptr->value = 0;
	ptr->rank = 0;
	return (ptr);
}

t_node	*create_assign_node(int value)
{
	t_node *node;

	node = create_node();
	node->value = value;
	return (node);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bot = NULL;
	return (stack);
}

t_env	*create_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->A = create_stack();
	env->B = create_stack();
	return (env);
}

