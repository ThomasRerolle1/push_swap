/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:10:29 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/06 13:05:21 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/*
void	pa(t_env *env)
{
	t_node *tmp;

	if (!env->B || env->B->size == 0)
		return;
	tmp = env->B->top;
	env->B->top = env->B->top->next;
	env->A->size += 1;
	env->B->size -= 1;
	if (!(env->A->top))
	{
		tmp->next = NULL;
		env->A->top = tmp;
		return ;
	}
	tmp->next = env->A->top;
	env->A->top->prev = tmp;
	env->A->top = tmp;
}	*/




void	pa(t_env *env)
{
	t_node	*tmp;

	if (!(env->B->top))
		return ;	
	tmp = env->B->top;
	if (!(env->B->top->next))
	{
		env->B->top = NULL;
		env->B->bot = NULL;
	}
	else
		env->B->top = env->B->top->next;
	tmp->prev = NULL;
	if (env->A->top)
	{
		env->A->top->prev = tmp;
		tmp->next = env->A->top;
	}
	else
		tmp->next = NULL;
	env->A->top = tmp;
	if (!env->A->bot)
		env->A->bot = tmp;
	env->A->size += 1;
	if ((env->B->size -= 1) == 1)
	{
		disconnect_node(env->B->top);
		disconnect_node(env->B->bot);
	}
	return ;
}

void	pb(t_env *env)
{
	t_node	*tmp;

	if (!(env->A->top))
		return ;	
	tmp = env->A->top;
	if (!(env->A->top->next))
	{
		env->A->top = NULL;
		env->A->bot = NULL;
	}
	else
	{
		env->A->top = env->A->top->next;
		env->A->top->prev = NULL;
	}
	tmp->prev = NULL;
	if (env->B->top)
	{
		env->B->top->prev = tmp;
		tmp->next = env->B->top;
	}
	else
		tmp->next = NULL;
	env->B->top = tmp;
	if (!env->B->bot)
		env->B->bot = tmp;
	env->B->size += 1;
	if ((env->A->size -= 1) == 1)
	{
		disconnect_node(env->A->top);
		disconnect_node(env->A->bot);
	}
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
	env->B->top = create_assign_node(4);
	env->B->size = 2;
	env->B->bot = create_assign_connect_node(env->B->top, "10");
	env->B->bot = create_assign_connect_node(env->B->bot, "9");
	env->B->bot = create_assign_connect_node(env->B->bot, "8");
	env->B->bot = create_assign_connect_node(env->B->bot, "7");
	pb(env);
	pb(env);
	pb(env);
	printf("size A %d\n", env->A->size);
	printf("size b %d\n", env->B->size);
	t_node	*cur_node = env->B->top;
	while (cur_node)
	{
		printf("value B : %d\n", cur_node->value);
		cur_node = cur_node->next;
	}
	cur_node = env->A->top;
	while (cur_node)
	{
		printf("value A : %d\n", cur_node->value);
		cur_node = cur_node->next;
	}
	return (0);
}*/
