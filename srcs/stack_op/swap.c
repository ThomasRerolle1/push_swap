/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:01:47 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/11 15:20:58 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_env *env)
{
	t_node	*tmp;

	if (env->a->size < 2)
		return ;
	tmp = env->a->top->next;
	env->a->top->next = env->a->top->next->next;
	if (env->a->top->next)
		env->a->top->next->prev = env->a->top;
	if (env->a->size == 2)
		env->a->bot = env->a->top;
	disconnect_node(tmp);
	tmp->next = env->a->top;
	env->a->top->prev = tmp;
	env->a->top = tmp;
	ft_putendl_fd("sa", 1);
}

void	sb(t_env *env)
{
	t_node	*tmp;

	if (env->b->size < 2)
		return ;
	tmp = env->b->top->next;
	env->b->top->next = env->b->top->next->next;
	if (env->b->top->next)
		env->b->top->next->prev = env->b->top;
	if (env->b->size == 2)
		env->b->bot = env->b->top;
	disconnect_node(tmp);
	tmp->next = env->b->top;
	env->b->top->prev = tmp;
	env->b->top = tmp;
	ft_putendl_fd("sb", 1);
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
