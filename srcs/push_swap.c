/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:56:10 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/30 15:37:11 by elaachac         ###   ########.fr       */
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

void	init_list(char **argv, t_list **a, t_list **b)
{
	int i;

	i = 1;
	*a = newlist();
	*b = newlist();
	while (argv[i])
	{
		add_tail_list(a, ft_atoi(argv[i]), 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	check_args(argc, argv);
	if (argc > 100)
	{
		init_list(argv, &a, &b);
		if (lcheck_sort(&a) == 0)
		{
			// args deja triés (rendu: il ne se passe rien, donc suppr le write)
			write(1, "done\n", 5);
			dellist(&a);
			dellist(&b);
			return (0);
		}
	}
	else
	{
		init_stack(argc, argv, &stack);
		if (check_sort(&stack) == 0)
		{
			// args deja triés (rendu: il ne se passe rien, donc suppr le write)
			write(1, "done\n", 5);
			return (0);
		}
		choose_case(&stack);
	}
	//			AFFICHER LES STACKS EN LISTES CHAINEES
		// t_node *iterator;
		// iterator = a->head;
		// int i = 0;
		// while (i < 100)
		// {
		// 	printf("value:%d\n", iterator->data);
		// 	iterator = iterator->next;
		// 	i++;
		// }
	dellist(&a);
	dellist(&b);
	//			AFFICHER LES STACKS EN INT*
	// printf("STACK A :\n#%d#\n", stack.a[0]);
	// printf("#%d#\n", stack.a[1]);
	// printf("#%d#\n", stack.a[2]);
	// printf("#%d#\n", stack.a[3]);
	// printf("#%d#\n", stack.a[4]);
	// printf("STACK B :\n.%d.\n", stack.b[0]);
	// printf(".%d.\n", stack.b[1]);
	// printf(".%d.\n", stack.b[2]);
	// printf(".%d.\n", stack.b[3]);
	// printf(".%d.\n", stack.b[4]);
	// system ("leaks push_swap");
}
