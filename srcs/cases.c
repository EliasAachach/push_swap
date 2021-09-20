/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:44:20 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/20 17:33:29 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_three(t_stack *stack)
{
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

	if (pos > stack->index_max_a / 2)
	{
		rev = 1;
		pos = stack->index_max_a - pos;
	}
	else
		rev = 0;
	while(pos > stack->sub_index_a)
	{
		if (rev == 1)
			reverse(stack, RRA);
		else
			rotate(stack, RA);
		pos--;
	}
	push(stack, PA);
}

void	case_five(t_stack *stack)
{
	int pos;

	while (stack->sub_index_a != 2)
		push(stack, PB);
	case_three(stack);
	printf("STACK A APRES 3 CASES\n{%d}\n", stack->a[0]);
	printf("{%d}\n", stack->a[1]);
	printf("{%d}\n", stack->a[2]);
	printf("{%d}\n", stack->a[3]);
	printf("{%d}\nFIN A APRES 3 CASES\n", stack->a[4]);
	while (stack->sub_index_b != stack->index_max_b)
	{
		pos = wich_pos(stack, stack->b[stack->sub_index_b]);
		five_move(stack, pos);
			printf("#%d#\n", stack->a[0]);
			printf("#%d#\n", stack->a[1]);
			printf("#%d#\n", stack->a[2]);
			printf("#%d#\n", stack->a[3]);
			printf("#%d#\n", stack->a[4]);
	}
}

void	choose_case(t_stack *stack)
{
	if (stack->index_max_a <= 3)
	{
		case_three(stack);
	}
	else if (stack->index_max_a <= 5)
	{
		// write(1, "5\n", 2);
		//CASE 5
		case_five(stack);
	}
	else if (stack->index_max_a <= 100)
	{
		write(1, "100\n", 4);
		//CASE 100
		// case_hundred(stack);
	}
}
