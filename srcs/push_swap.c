/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:56:10 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/18 14:34:14 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(char **argv, t_list **a, t_list **b)
{
	int		i;
	int		j;
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

int	else_main(char **argv, t_list **a, t_list **b)
{
	init_list(argv, a, b);
	if (lcheck_sort(a) == 0)
	{
		dellist(a);
		dellist(b);
		return (0);
	}
	choose_case(a, b);
	dellist(a);
	dellist(b);
	return (0);
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
			dellist(&a);
			dellist(&b);
			return (0);
		}
		lsort(&a, &b);
		dellist(&a);
		dellist(&b);
	}
	else
		else_main(argv, &a, &b);
	return (0);
}
