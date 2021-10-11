/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:27:18 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/08 12:01:42 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest(t_list **a)
{
	size_t	count;
	t_node	*iter_node;
	t_node	*smallest_node;

	count = 0;
	iter_node = (*a)->head;
	smallest_node = iter_node;
	while (smallest_node->chunk_pos != -1 && smallest_node->next != (*a)->head)
		smallest_node = smallest_node->next;
	while (count < (*a)->lenght)
	{
		iter_node = iter_node->next;
		if (smallest_node->data > iter_node->data && iter_node->chunk_pos == -1)
		{
			smallest_node = iter_node;
			iter_node = (*a)->head;
			count = 0;
		}
		else
			count++;
	}
	return (smallest_node);
}

int	set_chunk_pos(t_list **a)
{
	t_node	*smallest_node;
	size_t 	index_chunk;

	index_chunk = 0;
	while (index_chunk < (*a)->lenght)
	{
		smallest_node = find_smallest(a);
		smallest_node->chunk_pos = index_chunk;
		index_chunk++;
	}
	return (0);
}

void	push_chunk(t_list **a, t_list **b, int chunk_max, int chunk_iter)
{
	t_node	*tmp_node;
	size_t	index;

	index = 0;
	tmp_node = (*a)->head;
	while (index < (*a)->lenght)
	{
		while ((int)index <= chunk_max)
		{
			if (tmp_node->chunk_pos <= chunk_max)
			{
				printf("tmp:{%d}\n", tmp_node->data);
				while ((*a)->head->data != tmp_node->data)
				{
					lrotate(a, RA);
					printf("pa\n");
				}
				lpush(a, b, PB);
			}
		index++;
		tmp_node = tmp_node->next;
		}
		if (chunk_max + 1 < (int)((*a)->lenght))
			chunk_max += chunk_iter;
	}
}

void	lsort(t_list **a, t_list **b)
{
	int	chunk_max;
	int hun_fiv;

	if ((*a)->lenght < 500)
	{
		hun_fiv = 5;
		chunk_max = ((*a)->lenght / 5) - 1;
	}
	else
	{
		hun_fiv = 11;
		chunk_max = ((*a)->lenght / 11) - 1;
	}
	(*b)->lenght = (*b)->lenght; //ONLY USED TO SILENCE THE WARNING "B ISN'T USED"
	set_chunk_pos(a);
	push_chunk(a, b, chunk_max, chunk_max + 1);
}