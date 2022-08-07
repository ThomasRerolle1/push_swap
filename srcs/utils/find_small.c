/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:40:21 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/07 13:10:06 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_node	*find_two_smallest(t_env *env)
{
	t_node	*bot;
	t_node	*top;

	bot = env->A->bot;
	top = env->A->top;
	while (bot && top)
	{
		if (top->value == 1 || top->value == 2)
			return (top);
		if (bot->value == 1 || bot->value == 2)
			return (bot);
		bot = bot->prev;
		top = top->next;
	}
	return (NULL);
}

int	choose_ra_rra(t_env *env, t_node *smallest)
{
	t_node	*from_top;
	t_node	*from_bot;

	from_top = env->A->top;
	from_bot = env->A->bot;
	while (from_top && from_bot)
	{
		if (from_top == smallest)
			return (1);
		if (from_bot == smallest)
			return (2);
		from_top = from_top->next;
		from_bot = from_top->next;
	}
	return (0);
}

void	find_push_two_smallest(t_env *env)
{
	t_node	*smallest;

	smallest = find_two_smallest(env);
	if (choose_ra_rra(env, smallest) == 0)
		return ;
	if (choose_ra_rra(env, smallest) == 1)
	{
		while (env->A->top != smallest)
			ra(env);
	}
	else
	{
		while (env->A->top != smallest)
			rra(env);
	}
	pb(env);
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
	t_node	*smallest;
	smallest = find_two_smallest(env);
	int	i = choose_ra_rra(env, smallest);
	find_push_two_smallest(env);
	find_push_two_smallest(env);
	printf("value %i\nra ? rra : %i\n", smallest->value, i);
	return (0);
}*/
