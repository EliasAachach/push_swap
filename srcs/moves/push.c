/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:54:17 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/21 14:32:57 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int move)
{
	if (move == PA)
	{
		if (stack->sub_index_a > 0)
			stack->sub_index_a--;
		if (stack->sub_index_b > stack->index_max_b)
			stack->a[stack->sub_index_a] = stack->b[stack->sub_index_b - 1];
		stack->a[stack->sub_index_a] = stack->b[stack->sub_index_b];
		stack->sub_index_b++;
		ft_putstr("pa\n");
	}
	if (move == PB)
	{
		if (stack->sub_index_b > stack->index_max_b)
		{
			stack->b[stack->index_max_b] = stack->a[stack->sub_index_a];
		}
		else
			stack->b[stack->sub_index_b - 1] = stack->a[stack->sub_index_a];
		stack->sub_index_a++;
		if (stack->sub_index_b > 0)
			stack->sub_index_b--;
		ft_putstr("pb\n");
	}
}
