/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:10:29 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/11 15:20:38 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	change_size(t_env *env, char c)
{
	if (c == 'a')
	{
		env->a->size += 1;
		env->b->size -= 1;
		if (env->b->size == 1)
		{
			disconnect_node(env->b->top);
			disconnect_node(env->b->bot);
		}
	}
	else
	{
		env->b->size += 1;
		env->a->size -= 1;
		if (env->a->size == 1)
		{
			disconnect_node(env->a->top);
			disconnect_node(env->a->bot);
		}
	}
}

t_node	*check_if_null_a(t_env *env)
{
	t_node	*tmp;

	if (!env->b->top)
		return (NULL);
	tmp = env->b->top;
	if (!(env->b->top->next))
	{
		env->b->top = NULL;
		env->b->bot = NULL;
	}
	else
	{
		env->b->top = env->b->top->next;
		env->b->top->prev = NULL;
	}	
	tmp->prev = NULL;
	return (tmp);
}

t_node	*check_if_null_b(t_env *env)
{
	t_node	*tmp;

	if (!(env->a->top))
		return (NULL);
	tmp = env->a->top;
	if (!(env->a->top->next))
	{
		env->a->top = NULL;
		env->a->bot = NULL;
	}
	else
	{
		env->a->top = env->a->top->next;
		env->a->top->prev = NULL;
	}
	tmp->prev = NULL;
	return (tmp);
}	

void	pa(t_env *env)
{
	t_node	*tmp;

	tmp = check_if_null_a(env);
	if (tmp == NULL)
		return ;
	if (env->a->top)
	{
		env->a->top->prev = tmp;
		tmp->next = env->a->top;
	}
	else
		tmp->next = NULL;
	env->a->top = tmp;
	if (!env->a->bot)
		env->a->bot = tmp;
	change_size(env, 'a');
	ft_putendl_fd("pa", 1);
	return ;
}

void	pb(t_env *env)
{
	t_node	*tmp;

	tmp = check_if_null_b(env);
	if (tmp == NULL)
		return ;
	if (env->b->top)
	{
		env->b->top->prev = tmp;
		tmp->next = env->b->top;
	}
	else
		tmp->next = NULL;
	env->b->top = tmp;
	if (!env->b->bot)
		env->b->bot = tmp;
	change_size(env, 'b');
	ft_putendl_fd("pb", 1);
	return ;
}

/*
int	main(int argc, char **argv)
{
	t_env	*env;

	(void)argc;
	//if (argc < 2)
	//	return (0);
	env = create_env();
	parse_argv(env, &argv[1]);
	env->b->top = create_assign_node(4);
	env->b->size = 5;
	env->b->bot = create_assign_connect_node(env->b->top, "10");
	env->b->bot = create_assign_connect_node(env->b->bot, "9");
	env->b->bot = create_assign_connect_node(env->b->bot, "8");
	env->b->bot = create_assign_connect_node(env->b->bot, "7");
	pa(env);
	pa(env);
	pa(env);
	pb(env);
	pb(env);
	pb(env);
	pb(env);
	pb(env);
	pb(env);
	pb(env);
	pb(env);
	printf("size a %d\n", env->a->size);
	printf("size b %d\n", env->b->size);
	t_node	*cur_node = env->b->top;
	while (cur_node)
	{
		printf("value b : %d\n", cur_node->value);
		cur_node = cur_node->next;
	}
	cur_node = env->a->top;
	while (cur_node)
	{
		printf("value a : %d\n", cur_node->value);
		cur_node = cur_node->next;
	}
	return (0);
}*/
