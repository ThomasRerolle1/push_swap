/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:15:11 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/11 15:20:53 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_env *env)
{
	t_node	*tmp;

	if (env->a->size < 2)
		return ;
	tmp = env->a->top;
	env->a->top = env->a->top->next;
	env->a->top->prev = NULL;
	disconnect_node(tmp);
	tmp->prev = env->a->bot;
	env->a->bot->next = tmp;
	env->a->bot = tmp;
	ft_putendl_fd("ra", 1);
}

void	rb(t_env *env)
{
	t_node	*tmp;

	if (env->b->size < 2)
		return ;
	tmp = env->b->top;
	env->b->top = env->b->top->next;
	env->b->top->prev = NULL;
	disconnect_node(tmp);
	tmp->prev = env->b->bot;
	env->b->bot->next = tmp;
	env->b->bot = tmp;
	ft_putendl_fd("rb", 1);
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
	printf("size %d\n", env->a->size);
	t_node	*cur;
	cur = env->a->top;
	while (cur)
	{
		printf("value a : %d\n", cur->value);
		cur = cur->next;
	}
	env = clear_env(env);
	return (0);
}*/
