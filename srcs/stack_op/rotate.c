/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:15:11 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/06 14:14:39 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


void	ra(t_env *env)
{
	t_node	*tmp;

	if (env->A->size < 2)
		return ;
	tmp = env->A->top;
	env->A->top = env->A->top->next;
	env->A->top->prev = NULL;
	disconnect_node(tmp);
	tmp->prev = env->A->bot;
	env->A->bot->next = tmp;
	env->A->bot = tmp;
}

void	rb(t_env *env)
{
	t_node	*tmp;

	if (env->B->size < 2)
		return ;
	tmp = env->B->top;
	env->B->top = env->B->top->next;
	env->B->top->prev = NULL;
	disconnect_node(tmp);
	tmp->prev = env->B->bot;
	env->B->bot->next = tmp;
	env->B->bot = tmp;
}

void	rr(t_env *env)
{
	ra(env);
	rb(env);
}

/*
int	main(int argc, char **argv)
{
	t_env	*env;

	env = create_env();
	if (argc < 2)
		return (0);
	if (!(parse_argv(env, &argv[1])))
			return (0);

	ra(env);
	printf("size %d\n", env->A->size);
	t_node	*cur;
	cur = env->A->top;
	while (cur)
	{
		printf("value A : %d\n", cur->value);
		cur = cur->next;
	}
	env = clear_env(env);
	return (0);
}*/
