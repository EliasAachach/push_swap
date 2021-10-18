/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:40:43 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/18 14:58:48 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_f_h(size_t *cnt, int **wich_move)
{
	*cnt = 0;
	**wich_move = (int)*cnt;
}

t_node	*find_highest(t_list **b, int *wich_move)
{
	size_t	count;
	t_node	*iter_node;
	t_node	*highest_node;

	init_f_h(&count, &wich_move);
	iter_node = (*b)->head;
	highest_node = iter_node;
	while (count < (*b)->lenght)
	{
		iter_node = iter_node->next;
		if (highest_node->data < iter_node->data)
		{
			highest_node = iter_node;
			iter_node = (*b)->head;
			*wich_move = count;
			count = 0;
		}
		else
			count++;
	}
	if (*wich_move > (int)(*b)->lenght / 2)
		*wich_move = 1;
	else
		*wich_move = 0;
	return (highest_node);
}
