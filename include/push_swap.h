/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 07:51:09 by trerolle          #+#    #+#             */
/*   Updated: 2022/08/07 14:25:42 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_env{
	struct s_stack	*A;
	struct s_stack	*B;
}		t_env;

typedef struct	s_stack{
	int		size;
	struct s_node	*top;
	struct s_node	*bot;
}	t_stack;

typedef struct s_node{
	int		value;
	int		rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;



int	check_is_num(char *str);
int check_int(char	*str);
int	check_dup(t_env *env);
long	ft_atol(char *str);
t_node	*create_node(void);
t_node	*create_assign_node(int value);
t_stack	*create_stack(void);
t_env	*create_env(void);
void	clear_nodes(t_node *top);
t_stack	*clear_stack(t_stack *stack);
t_env	*clear_env(t_env *env);
void	clear_str(char	*str);
char	**clear_av(char **av);
void	connect_node(t_node *cur_node, t_node *next_node);
t_node	*create_assign_connect_node(t_node *cur_node, char *str);
t_stack	*link_nodes_to_stack(t_stack *A, t_node *bot_node);
void	disconnect_node(t_node *node);
int	parse_argv(t_env *env, char **argv);
void	pa(t_env *env);
void	pb(t_env *env);
void	sa(t_env *env);
void	sb(t_env *env);
void	ra(t_env *env);
void	rb(t_env *env);
void	rr(t_env *env);
void	rra(t_env *env);
void	rrb(t_env *env);
void	rrr(t_env *env);
void	copy_value_in_rank(t_env *env);
void	sort_values(t_env *env);
void	find_index(t_stack *A, t_node *cur_node);
void	convert_numbers_into_index(t_env *env);
void	fill_copy_rank_in_value(t_env *env);
t_node	*find_two_smallest(t_env *env);
int		choose_ra_rra(t_env *env, t_node *smallest);
void	find_push_two_smallest(t_env *env);
void	sort_three_nums(t_env *env);
void	sort_five_nums(t_env *env);
int		is_sorted(t_env *env);
void	radix(t_env *env);
void	exit_error(char *str, int argc, char **av, t_env *env);
