/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:27:10 by trerolle          #+#    #+#             */
/*   Updated: 2022/04/07 15:33:45 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "operations.c"
# include <stdio.h>

typedef struct	s_stack
{
	char			name;
	int				number;
	int				index;
	struct s_stack	prev;
	struct s_stack	next;
}				t_stack;

