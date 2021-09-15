/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:34:03 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/15 12:28:20 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"


void	case_three(t_stack *stack)
{
	if (stack->a[0] == 2 && stack->a[1] == 1 && stack->a[2] == 3)
	{
		swap(stack, SA);
		return ;
	}
	if (stack->a[0] == 3 && stack->a[1] == 2 && stack->a[2] == 1)
	{
		swap(stack, SA);
		reverse(stack, RRA);
		return ;
	}
	if (stack->a[0] == 3 && stack->a[1] == 1 && stack->a[2] == 2)
	{
		rotate(stack, RA);
		return ;
	}
	if (stack->a[0] == 1 && stack->a[1] == 3 && stack->a[2] == 2)
	{
		swap(stack, SA);
		rotate(stack, SA);
		return ;
	}
	if (stack->a[0] == 2 && stack->a[1] == 3 && stack->a[2] == 1)
	{
		reverse(stack, RRA);
		return ;
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
		write(1, "5\n", 2);
		//CASE 5
		// case_five(stack);
	}
	if (stack->index_max_a <= 100)
	{
		write(1, "100\n", 3);
		//CASE 100
		// case_hundred(stack);
	}
}