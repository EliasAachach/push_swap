/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:54:17 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/17 17:56:59 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int move)
{
	if (move == PA && stack->b[stack->sub_index_b] != '\0')
	{
		if (stack->sub_index_a > 0)
			stack->sub_index_a--;
		stack->a[stack->sub_index_a] = stack->b[stack->sub_index_b];
		stack->sub_index_b++;
		ft_putstr("pa\n");
	}
	if (move == PB && stack->a[stack->sub_index_a] != '\0')
	{
		if (stack->sub_index_b > 0)
			stack->sub_index_b--;
		stack->b[stack->sub_index_b] = stack->a[stack->sub_index_a];
		stack->sub_index_a++;
		ft_putstr("pb\n");
	}
}
