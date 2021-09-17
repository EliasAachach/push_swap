/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:37:15 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/17 17:57:02 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_end(t_stack *stack, int move)
{
	int i;
	int tmp;

	tmp = 0;
	if (move == RRB || move == RRR)
	{
		tmp = stack->b[stack->index_max_b];
		i = stack->index_max_b;
		while (i > stack->sub_index_b)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		if (i == stack->index_max_b)
			stack->b[0 + stack->sub_index_b] = tmp;
		if (move!= RRR)
			ft_putstr("rrb\n");
	}
	if (move == RRR)
		ft_putstr("rrr\n");
}

void	reverse(t_stack *stack, int move)
{
	int i;
	int tmp;

	tmp = 0;
	if (move == RRA || move == RRR)
	{
		tmp = stack->a[stack->index_max_a];
		i = stack->index_max_a;
		while (i > stack->sub_index_a)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		if (i == stack->sub_index_a)
			stack->a[stack->sub_index_a] = tmp;
		if (move != RRR)
			ft_putstr("rra\n");
	}
	reverse_end(stack, move);
}