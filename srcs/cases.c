/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:44:20 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/23 15:40:31 by elaachac         ###   ########.fr       */
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
	// if (pos > stack->index_max_a / 2)
	// {
	// 	rev = 1;
	// 	pos = stack->index_max_a - pos;
	// }
	// else
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

void	case_five(t_stack *stack)
{
	int pos;

	while (stack->index_max_a - stack->sub_index_a > 2)
		push(stack, PB);
	case_three(stack);
	while (stack->sub_index_b <= stack->index_max_b)
	{
		pos = wich_pos(stack, stack->b[stack->sub_index_b]);
		five_move(stack, pos);
	}
}

 void	case_hundred(t_stack *stack)
 {
	stack->index_max_a += 0;
	return ;
 }

void	choose_case(t_stack *stack)
{
	if (stack->index_max_a <= 2)
	{
		case_three(stack);
	}
	else if (stack->index_max_a <= 4)
	{
		case_five(stack);
	}
	else if (stack->index_max_a <= 99)
	{
		printf("max:%d\n", stack->index_max_a);
		write(1, "100\n", 4);
		//CASE 100
		// case_hundred(stack);
	}
}
