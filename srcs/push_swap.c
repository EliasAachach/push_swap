/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:56:10 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/20 16:17:36 by elaachac         ###   ########.fr       */
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
			if (ft_atoi_check(tmp[j]) == 1)
			{
				dellist(a);
				dellist(b);
				free_split(tmp);
				error_prog(0);
			}
			add_tail_list(a, ft_atoi(tmp[j++]));
		}
		i++;
		free_split(tmp);
	}
}

int	else_main(t_list **a, t_list **b)
{
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
	init_list(argv, &a, &b);
	if (a->lenght == 100 || a->lenght == 500)
	{
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
		else_main(&a, &b);
	return (0);
}
