/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:42:37 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/11 15:20:45 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_env *env)
{
	t_node	*tmp;

	if (env->a->size < 2)
		return ;
	tmp = env->a->bot;
	env->a->bot = env->a->bot->prev;
	env->a->bot->next = NULL;
	disconnect_node(tmp);
	tmp->next = env->a->top;
	env->a->top->prev = tmp;
	env->a->top = tmp;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_env *env)
{
	t_node	*tmp;

	if (env->b->size < 2)
		return ;
	tmp = env->b->bot;
	env->b->bot = env->b->bot->next;
	env->b->bot->next = NULL;
	disconnect_node(tmp);
	tmp->next = env->b->top;
	env->b->top->prev = tmp;
	env->b->top = tmp;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_env *env)
{
	rra(env);
	rrb(env);
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
	rra(env);
	return (0);
}*/
