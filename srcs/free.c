/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 07:48:07 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/03 08:01:36 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"


void	clear_nodes(t_node *top)
{
	t_node	*tmp;

	if (!top)
		return ;
	while (top)
	{
		tmp = top->next;
		free(top);
		top = tmp;
	}
	top = NULL;
	return ;
}

t_stack	*clear_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (stack->top)
		clear_nodes(stack->top);
	free(stack);
	return (NULL);
}


t_env	*clear_env(t_env *env)
{
	if (!env)
		return (NULL);
	if (env->A)
		env->A = clear_stack(env->A);
	if (env->B)
		env->B = clear_stack(env->B);
	free(env);
	return (NULL);
}

