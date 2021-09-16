/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:18:57 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/16 12:07:39 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, int move)
{
	int tmp;

	if ((move == SA || move == SS) && stack->sub_index_a\
		<= stack->index_max_a - 1)
	{
		tmp = stack->a[stack->sub_index_a];
		stack->a[stack->sub_index_a] = stack->a[1 + stack->sub_index_a];
		stack->a[1 + stack->sub_index_a] = tmp;
		if (move != SS)
			ft_putstr("sa\n");
	}
	if ((move == SB || move == SS) &&\
		stack->sub_index_b <= stack->index_max_b - 1)
	{
		tmp = stack->b[stack->sub_index_b];
		stack->b[stack->sub_index_b] = stack->b[1 + stack->sub_index_b];
		stack->b[1 + stack->sub_index_b] = tmp;
		if (move != SS)
			ft_putstr("sb\n");
	}
	if (move == SS)
		ft_putstr("ss\n");
}