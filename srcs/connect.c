/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:58:31 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/11 15:17:49 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	connect_node(t_node *cur_node, t_node *next_node)
{
	if (cur_node)
		cur_node->next = next_node;
	next_node->prev = cur_node;
}

t_node	*create_assign_connect_node(t_node *cur_node, char *str)
{
	t_node	*next_node;

	next_node = create_assign_node(ft_atoi(str));
	connect_node(cur_node, next_node);
	return (next_node);
}

t_stack	*link_nodes_to_stack(t_stack *a, t_node *bot_node)
{
	t_node	*top_node;

	if (!bot_node)
		return (a);
	top_node = bot_node;
	a->bot = bot_node;
	while (top_node->prev)
	{
		top_node = top_node->prev;
	}
	a->top = top_node;
	return (a);
}

void	disconnect_node(t_node *node)
{
	if (node)
	{
		node->prev = NULL;
		node->next = NULL;
	}
}
