/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:11:49 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/07 14:22:34 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_error(char *str, int argc, char **av, t_env *env)
{
	ft_putendl_fd(str, 1);
	if (env)
		env = clear_env(env);
	if (argc == 2)
		av = clear_av(av);
	exit(EXIT_FAILURE);
}

void	choose_sorting_algo(t_env *env)
{
	fill_copy_rank_in_value(env);
	if (env->A->size == 3)
		sort_three_nums(env);
	if (env->B->size == 5)
		sort_five_nums(env);
	else
		radix(env);
}

/* peut etre faire retour t_env pour directement assigner NULL a env dans la fct main
 */
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
	if (!(env = create_env()) || !parse_argv(env, av))
		exit_error("Error\n", argc, av, env);
	choose_sorting_algo(env);
	env = clear_env(env);
	exit(EXIT_SUCCESS);
	return (0);
}
