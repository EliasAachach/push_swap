/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:56:10 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/14 17:09:37 by elaachac         ###   ########.fr       */
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
	int	j;
	char	**tmp;

	i = 1;
	*a = newlist();
	*b = newlist();
	while (argv[i])
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j] != NULL)
		{
			add_tail_list(a, ft_atoi(tmp[j++]));
		}
		i++;
		free_split(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	check_args(argc, argv);
	if (argc - 1 == 100 || argc - 1 == 500)
	{
		init_list(argv, &a, &b);
		if (lcheck_sort(&a) == 0)
		{
			// args deja triés (rendu: il ne se passe rien, donc suppr le write)
			dellist(&a);
			dellist(&b);
			return (0);
		}
		lsort(&a, &b);
		dellist(&a);
		dellist(&b);
	}
	else
	{
		init_list(argv, &a, &b);
		if (lcheck_sort(&a) == 0)
		{
			// args deja triés (rendu: il ne se passe rien, donc suppr le write)
			dellist(&a);
			dellist(&b);
			return (0);
		}
		choose_case(&a, &b);
		dellist(&a);
		dellist(&b);
	}
	return (0);
}
