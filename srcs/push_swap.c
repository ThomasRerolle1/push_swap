/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:11:49 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/03 15:50:34 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_error(char *str, int i)
{
	ft_putendl_fd(str, 1);
	if (i == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}


//void	parse_argv(t_env *env, char **argv)
//{
//
//
//
//
//


/* peut etre faire retour t_env pour directement assigner NULL a env dans la fct main
 */
/*
int	main(int argc, char **argv)
{
	t_env	*env;
	char	**av;

	if (argc < 2)
		return (0);
	if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
		av = &argv[1];
	env = create_env();
	if (!env)
		return (0);

	env->A->size = argc - 1;
	//env->A->top = assign_node(2);

	printf("env : %p\nA : %p\nB : %p\nA->top : %p\n", env, env->A, env->B, env->A->top);
	if (!parse_argv(env, av))
		printf("failed to parse\n");
	else
		printf("successfuly parsed\n");

	t_node	*cur_node = env->A->top;
	while (cur_node)
	{
		printf("value : %d\n", cur_node->value);
		cur_node = cur_node->next;
	}
	printf("env : %p\n", env);
	env = clear_env(env);
	//choose_algo(logs);
	exit(EXIT_SUCCESS);
	return (0);
}*/
