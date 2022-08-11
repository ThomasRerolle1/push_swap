/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 07:48:07 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/11 15:19:26 by trerolle         ###   ########.fr       */
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
		top = NULL;
		top = tmp;
	}
	return ;
}

t_stack	*clear_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (stack->top)
		clear_nodes(stack->top);
	free(stack);
	stack = NULL;
	return (NULL);
}

t_env	*clear_env(t_env *env)
{
	if (!env)
		return (NULL);
	if (env->a)
		env->a = clear_stack(env->a);
	if (env->b)
		env->b = clear_stack(env->b);
	free(env);
	env = NULL;
	return (NULL);
}

void	clear_str(char	*str)
{
	if (*str)
		free(str);
	str = NULL;
}

void	clear_av(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		free(av[i]);
		av[i] = NULL;
		i++;
	}
	free(av);
	av = NULL;
	return ;
}
