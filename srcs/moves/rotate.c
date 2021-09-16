/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:56:45 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/16 12:57:37 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_end(t_stack *stack, int move)
{
	int i;
	int tmp;

	tmp = 0;
	if (move == RB || move == RR)
	{
		tmp = stack->b[stack->sub_index_b];
		i = stack->sub_index_b;
		while (i < stack->index_max_b)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		if (i == stack->index_max_b)
			stack->b[stack->index_max_b] = tmp;
		if (move!= RR)
			ft_putstr("rb\n");
	}
	if (move == RR)
		ft_putstr("rr\n");
}

void	rotate(t_stack *stack, int move)
{
	int i;
	int tmp;

	tmp = 0;
	if (move == RA || move == RR)
	{
		tmp = stack->a[stack->sub_index_a];
		i = stack->sub_index_a;
		while (i < stack->index_max_a)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		if (i == stack->index_max_a)
			stack->a[stack->index_max_a] = tmp;
		if (move != RR)
			ft_putstr("ra\n");
	}
	rotate_end(stack, move);
}