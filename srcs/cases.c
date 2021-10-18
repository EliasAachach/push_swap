/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:44:20 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/18 14:40:34 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_three(t_list **a)
{
	if (lcheck_sort(a) == 0)
		return ;
	if (wich_case(a) == 1)
		lswap(a, SA);
	else if (wich_case(a) == 2)
	{
		lswap(a, SA);
		lreverse(a, RRA);
		return ;
	}
	else if (wich_case(a) == 3)
		lrotate(a, RA);
	else if (wich_case(a) == 4)
	{
		lswap(a, SA);
		lrotate(a, RA);
		return ;
	}
	else if (wich_case(a) == 5)
		lreverse(a, RRA);
}

void	case_five(t_list **a, t_list **b)
{
	t_node	*smallest;
	int		pos;

	pos = 0;
	while ((*a)->lenght > 3)
	{
		smallest = find_smallest(a, &pos);
		while ((*a)->head->data != smallest->data)
		{
			if (pos < (int)(*a)->lenght / 2)
				lrotate(a, RA);
			else
				lreverse(a, RA);
		}
		lpush(a, b, PB);
	}
	case_three(a);
	while ((*b)->lenght > 0)
		lpush(a, b, PA);
}

void	choose_case(t_list **a, t_list **b)
{
	if ((*a)->lenght == 2)
		lswap(a, SA);
	else if ((*a)->lenght == 3)
		case_three(a);
	else if ((*a)->lenght > 3)
		case_five(a, b);
}
