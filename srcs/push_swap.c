/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:56:10 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/28 21:28:29 by elaachac         ###   ########.fr       */
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
	stack->sub_index_b = argc - 1;
}

void	init_list(int argc, char **argv, t_list *a, t_list *b)
{
	int i;

	i = 1;
	*a = newlist(argc - 1);
	*b = newlist(argc - 1);
	while (argv[i])
	{
		add_tail_list(&a)->data = ft_atoi(argv[i]);
		i++;
		printf("c ok\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_list	a;
	t_list	b;

	check_args(argc, argv);
	if (argc > 100)
		init_list(argc, argv, &a, &b);
	else
		init_stack(argc, argv, &stack);
	if (check_sort(&stack) == 0)
	{
		// args deja triés (rendu: il ne se passe rien, donc suppr le write)
		write(1, "done\n", 5);
		return (0);
	}
	choose_case(&stack);
	printf("STACK A :\n#%d#\n", stack.a[0]);
	printf("#%d#\n", stack.a[1]);
	printf("#%d#\n", stack.a[2]);
	printf("#%d#\n", stack.a[3]);
	printf("#%d#\n", stack.a[4]);
	printf("STACK B :\n.%d.\n", stack.b[0]);
	printf(".%d.\n", stack.b[1]);
	printf(".%d.\n", stack.b[2]);
	printf(".%d.\n", stack.b[3]);
	printf(".%d.\n", stack.b[4]);
	// system ("leaks push_swap");
}
