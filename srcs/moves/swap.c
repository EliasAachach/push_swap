/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:18:57 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/15 16:36:50 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, int move)
{
	int tmp;

	if ((move == SA || move == SS) && stack->sub_index_a\
		<= stack->index_max_a - 1)
	{
		tmp = stack->a[0 + stack->sub_index_a];
		stack->a[0 + stack->sub_index_a] = stack->a[1 + stack->sub_index_a];
		stack->a[1 + stack->sub_index_b] = tmp;
		if (move != SS)
			ft_putchar("sa\n");
	}
	if ((move == SB || move == SS) &&\
		stack->sub_index_b <= stack->index_max_b - 1)
	{
		tmp = stack->b[0 + stack->sub_index_b];
		stack->b[0 + stack->sub_index_b] = stack->b[1 + stack->sub_index_b];
		stack->b[1 + stack->sub_index_b] = tmp;
		if (move != SS)
			ft_putchar("sb\n");
	}
	if (move == SS)
		ft_putchar("ss\n");
}