/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:56:10 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/20 17:35:04 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(int argc, char **argv, t_stack *stack)
{
	int i;

	i = 0;
	set_stacks(argc, argv, stack);
	stack->index_max_a = argc - 2;
	stack->index_max_b = argc - 2;
	stack->sub_index_a = 0;
	stack->sub_index_b = argc - 2;
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	check_args(argc, argv);
	init_stack(argc, argv, &stack);
	if (check_sort(&stack) == 0)
	{
		// args deja triés (rendu: il ne se passe rien, donc suppr le write)
		write(1, "done\n", 5);
		return (0);
	}
	choose_case(&stack);
		// int i = 0;
		// while (stack.a[i])
		// {
		// 	printf("{%d}\n", stack.a[i]);
		// 	i++;
		// }
			printf("STACK B :\n.%d.\n", stack.b[0]);
			printf(".%d.\n", stack.b[1]);
			printf(".%d.\n", stack.b[2]);
			printf(".%d.\n", stack.b[3]);
			printf(".%d.\n", stack.b[4]);
		// int y = 0;
		// while (stack.b[y])
		// {
		// 	printf(".%d.\n", stack.b[y]);
		// 	y++;
		// }
	// system ("leaks push_swap");
}
	