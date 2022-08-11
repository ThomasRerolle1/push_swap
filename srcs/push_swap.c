/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:11:49 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/11 15:20:13 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_error(char *str, int argc, char **av, t_env *env)
{
	(void)av;
	ft_putendl_fd(str, 2);
	if (env)
		env = clear_env(env);
	if (argc == 2)
		clear_av(av);
	exit(EXIT_FAILURE);
}

void	choose_sorting_algo(t_env *env)
{
	fill_copy_rank_in_value(env);
	if (env->a->size == 3)
		sort_three_nums(env);
	if (env->a->size == 5)
		sort_five_nums(env);
	else
		radix(env);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	char	**av;
	t_node	*node_test;

	if (argc < 2)
	{
		return (0);
	}
	if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
		av = &argv[1];
	env = create_env();
	if (!env || parse_argv(env, av) == 0)
		exit_error("Error", argc, av, env);
	choose_sorting_algo(env);
	if (argc == 2)
		clear_av(av);
	av = NULL;
	node_test = env->a->top->next;
	env = clear_env(env);
	exit(EXIT_SUCCESS);
	return (0);
}
