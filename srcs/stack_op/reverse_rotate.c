/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:42:37 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/07 11:50:41 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_env *env)
{
	t_node	*tmp;
	
	if (env->A->size < 2)
		return ;
	tmp = env->A->bot;
	env->A->bot = env->A->bot->prev;
	env->A->bot->next = NULL;
	disconnect_node(tmp);
	tmp->next = env->A->top;
	env->A->top->prev = tmp;
	env->A->top = tmp;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_env *env)
{
	t_node *tmp;

	if (env->B->size < 2)
		return ;
	tmp = env->B->bot;
	env->B->bot = env->B->bot->next;
	env->B->bot->next = NULL;
	disconnect_node(tmp);
	tmp->next = env->B->top;
	env->B->top->prev = tmp;
	env->B->top = tmp;
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
