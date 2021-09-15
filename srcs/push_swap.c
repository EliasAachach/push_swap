/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:56:10 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/15 14:49:49 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init(int argc, char **argv, t_stack *stack)
{
	set_stacks(argc, argv, stack);
	stack->index_max_a = argc - 1;
	stack->index_max_b = argc - 1;
	stack->sub_index_a = 0;
	stack->sub_index_b = argc - 1;
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	check_args(argc, argv);
	init(argc, argv, &stack);
	if (check_sort(stack.a) == 0)
	{
		// args deja triés
		write(1, "done\n", 5);
		return (0);
	}
	int i = 0;
	while (stack.a[i])
	{
		printf("%d\n", stack.a[i]);
		i++;
	}
	// choose_case(&stack);
	system ("leaks push_swap");
}
