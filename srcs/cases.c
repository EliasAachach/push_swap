/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:44:20 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/13 14:17:21 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_three(t_stack *stack)
{
	if (check_sort(stack) == 0)
		return ;
	if (wich_case(stack) == 1)
		swap(stack, SA);
	else if (wich_case(stack) == 2)
	{
		swap(stack, SA);
		reverse(stack, RRA);
		return ;
	}
	else if (wich_case(stack) == 3)
		rotate(stack, RA);
	else if (wich_case(stack) == 4)
	{
		swap(stack, SA);
		rotate(stack, RA);
		return ;
	}
	else if (wich_case(stack) == 5)
		reverse(stack, RRA);
}

void	five_move(t_stack *stack, int pos)
{
	int rev;
	int tmp_sub;

	push(stack, PA);
	tmp_sub = stack->sub_index_a;
	rev = 0;
	if (pos == stack->index_max_a)
	{
		rotate(stack, RA);
	}
	else
	{
		while(pos > tmp_sub)
		{
			swap(stack, SA);
			pos--;
			stack->sub_index_a++;
		}
	}
	stack->sub_index_a = tmp_sub;
}

void	min_to_top(t_stack *stack)
{
	int	i;
	int	min;
	int	index_min;

	i = stack->sub_index_a;
	min = stack->a[stack->sub_index_a];
	while (i <= stack->index_max_a)
	{
		if (min > stack->a[i])
		{
			index_min = i;
			min = stack->a[i];
		}
		i++;
	}
	while (stack->a[stack->sub_index_a] != min)
	{
		if (index_min > stack->index_max_a / 2)
			reverse(stack, RRA);
		else
			rotate(stack, RA);
	}
}

void	case_five(t_stack *stack)
{
	int pos;

	while (stack->index_max_a - stack->sub_index_a > 2)
	{
		min_to_top(stack);
		push(stack, PB);
	}
	case_three(stack);
	while (stack->sub_index_b <= stack->index_max_b)
	{
		pos = wich_pos(stack, stack->b[stack->sub_index_b]);
		five_move(stack, pos);
	}
}

void	choose_case(t_stack *stack)
{
	if (stack->index_max_a == 1)
	{
		swap(stack, SA);
	}
	if (stack->index_max_a == 2)
	{
		case_three(stack);
	}
	else
	{
		case_five(stack);
	}
}
