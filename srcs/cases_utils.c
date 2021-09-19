/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:31:39 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/19 19:41:10 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	wich_pos(t_stack *stack, int num)
{
	int i;

	i = stack->sub_index_a + 1;
	if (stack->a[stack->sub_index_a] > num)
		return (stack->sub_index_a);
	while (i < stack->index_max_a)
	{
		if (stack->a[i] < num && stack->a[i + 1] > num)
			return (i);
		i++;
	}
	if (stack->a[stack->index_max_a] < num)
		return (stack->index_max_a);
	return (-1);
}

int	wich_case(t_stack *stack)
{
	if ((stack->a[stack->sub_index_a] > stack->a[stack->sub_index_a + 1]\
		&& stack->a[stack->sub_index_a] < stack->a[stack->sub_index_a + 2]))
		return (1);
	if ((stack->a[stack->sub_index_a] > stack->a[stack->sub_index_a + 1]\
		&& stack->a[stack->sub_index_a] > stack->a[stack->sub_index_a +2]) &&\
		(stack->a[stack->sub_index_a + 1] > stack->a[stack->sub_index_a + 2]))
		return (2);
	if ((stack->a[stack->sub_index_a] > stack->a[stack->sub_index_a + 1]\
		&& stack->a[stack->sub_index_a] > stack->a[stack->sub_index_a +2]) &&\
		(stack->a[stack->sub_index_a + 1] < stack->a[stack->sub_index_a +2]))
		return (3);
	if ((stack->a[stack->sub_index_a] < stack->a[stack->sub_index_a + 1] &&\
		stack->a[stack->sub_index_a] < stack->a[stack->sub_index_a + 2]))
		return (4);
	if ((stack->a[stack->sub_index_a] < stack->a[stack->sub_index_a + 1] &&\
		stack->a[stack->sub_index_a] > stack->a[stack->sub_index_a + 2]))
		return (5);
	
	return (0);
}
