/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:27:18 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/18 13:21:54 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_chunk_pos(t_list **a)
{
	t_node	*smallest_node;
	size_t	index_chunk;
	int		pos;

	pos = 0;
	index_chunk = 0;
	while (index_chunk < (*a)->lenght)
	{
		smallest_node = find_smallest(a, &pos);
		smallest_node->chunk_pos = index_chunk;
		index_chunk++;
	}
	return (0);
}

void	push_chunk2(t_list **a, t_list **b, int *chunk_filled, int *index)
{
	lpush(a, b, PB);
	*chunk_filled += 1;
	*index = 0;
}

void	push_chunk(t_list **a, t_list **b, int chunk_max, int chunk_iter)
{
	t_node	*tmp_node;
	size_t	max_len;
	int		chunk_filled;
	int		index;

	chunk_filled = 0;
	max_len = (*a)->lenght;
	index = 0;
	while (index < (int)(*a)->lenght && (*a)->head)
	{
		while (chunk_filled <= chunk_max && (*a)->head)
		{
			tmp_node = (*a)->head;
			if (tmp_node->chunk_pos <= chunk_max)
			{
				push_chunk2(a, b, &chunk_filled, &index);
			}
			else
				lrotate(a, RA);
			index++;
		}
		if (chunk_max + 1 < (int)(max_len))
			chunk_max += chunk_iter;
	}
}

void	sort_push(t_list **a, t_list **b)
{
	t_node	*highest_node;
	int		wich_move;

	while ((*b)->head != NULL)
	{
		wich_move = 0;
		highest_node = find_highest(b, &wich_move);
		while ((*b)->head->data != highest_node->data)
		{
			if (wich_move == 0)
			{
				lrotate(b, RB);
			}
			else
			{
				lreverse(b, RB);
			}
		}
		lpush(a, b, PA);
	}
}

void	lsort(t_list **a, t_list **b)
{
	int	chunk_max;
	int	hun_fiv;

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
	set_chunk_pos(a);
	push_chunk(a, b, chunk_max, chunk_max + 1);
	sort_push(a, b);
}
