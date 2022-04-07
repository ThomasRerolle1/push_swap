/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:26:00 by trerolle          #+#    #+#             */
/*   Updated: 2022/04/07 15:35:37 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main()
{
	t_stack	*stack_a;
	t_stack	*new;
	int	i;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	new = (t_stack *)malloc(sizeof(t_stack));
	stack_a->name = 'a';
	i = 0;
	ft_lstclear(stack_a, del);
	return (0);
}
