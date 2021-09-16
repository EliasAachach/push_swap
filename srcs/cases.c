/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:44:20 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/16 15:10:12 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	wich_case(t_stack *stack)
{
	if ((stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2]))
		return (1);
	if ((stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2]) &&\
		(stack->a[1] > stack->a[2]))
		return (2);
	if ((stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2]) &&\
		(stack->a[1] < stack->a[2]))
		return (3);
	if ((stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2]))
		return (4);
	if ((stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2]))
		return (5);
	
	return (0);
}

void	case_three(t_stack *stack)
{
	if (wich_case(stack) == 1)
	{
		swap(stack, SA);
		return ;
	}
	if (wich_case(stack) == 2)
	{
		swap(stack, SA);
		reverse(stack, RRA);
		return ;
	}
	if (wich_case(stack) == 3)
	{
		rotate(stack, RA);
		return ;
	}
	if (wich_case(stack) == 4)
	{
		swap(stack, SA);
		rotate(stack, RA);
		return ;
	}
	if (wich_case(stack) == 5)
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
	else if (stack->index_max_a <= 100)
	{
		write(1, "100\n", 4);
		//CASE 100
		// case_hundred(stack);
	}
}