/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:34:03 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/14 16:36:31 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"


void	case_three(t_stack *stack)
{
	
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