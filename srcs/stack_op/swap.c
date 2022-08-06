/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:01:47 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/06 14:12:11 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_env *env)
{
	t_node	*tmp;

	if (env->A->size < 2)
		return ;
	tmp = env->A->top->next;
	env->A->top->next = env->A->top->next->next;
	if (env->A->top->next)
		env->A->top->next->prev = env->A->top;
	if (env->A->size == 2)
		env->A->bot = env->A->top;
	disconnect_node(tmp);
	tmp->next = env->A->top;
	env->A->top->prev = tmp;
	env->A->top = tmp;
}

void	sb(t_env *env)
{
	t_node	*tmp;

	if (env->B->size < 2)
		return ;
	tmp = env->B->top->next;
	env->B->top->next = env->B->top->next->next;
	if (env->B->top->next)
		env->B->top->next->prev = env->B->top;
	if (env->B->size == 2)
		env->B->bot = env->B->top;
	disconnect_node(tmp);
	tmp->next = env->B->top;
	env->B->top->prev = tmp;
	env->B->top = tmp;
}

void	ss(t_env *env)
{
	sa(env);
	sb(env);
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
	pb(env);
	pb(env);
	pb(env);
	pb(env);
	pb(env);
	pb(env);
	pb(env);
	sb(env);
	env = clear_env(env);
	return (0);
}*/
