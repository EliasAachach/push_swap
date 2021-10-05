/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:27:18 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/05 16:29:04 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_smallest(t_list ***a, int max_chunk)
// {
// 	t_node	*top;
// 	int		count;
// 	int		pos_min;
// 	int		smallest;

// 	top = *(*a)->head;
// 	smallest = (*a)->head->data;
// 	pos_min = 0;
// 	count = 0;
// 	while (top.next != (*a)->head && count <= max_chunk)
// 	{
// 		count++;
// 		top = top->next;
// 		if (top.data < smallest)
// 		{
// 			smallest = top.data;
// 			pos_min = count;
// 		}
// 	}
// 	return (pos_min);
// }

void	chunk_500(t_chunks *chunks, size_t stack_len)
{
	chunks->q1 = (stack_len / 11) - 1;
	chunks->q2 = (stack_len / 10) - 1;
	chunks->q3 = (stack_len / 9) - 1;
	chunks->q4 = (stack_len / 8) - 1;
	chunks->q5 = (stack_len / 7) - 1;
	chunks->q6 = (stack_len / 6) - 1;
	chunks->q7 = (stack_len / 5) - 1;
	chunks->q8 = (stack_len / 4) - 1;
	chunks->q9 = (stack_len / 3) - 1;
	chunks->q10 = (stack_len / 2) - 1;
	chunks->q11 = (stack_len / 1) - 1;
}

void	init_chunk(t_chunks *chunks, size_t stack_len)
{
	if (stack_len < 500)
	{
		chunks->q1 = (stack_len / 5) - 1;
		chunks->q2 = (stack_len / 4) - 1;
		chunks->q3 = (stack_len / 3) - 1;
		chunks->q4 = (stack_len / 2) - 1;
		chunks->q5 = (stack_len / 1) - 1;
		chunks->q6 = 0;
		chunks->q7 = 0;
		chunks->q8 = 0;
		chunks->q9 = 0;
		chunks->q10 = 0;
		chunks->q11 = 0;
	}
	else
		chunk_500(chunks, stack_len);

}

int	find_smallest(t_list **a, int max_chunk)
{
	t_node *test;

	test = (**a).head;
	printf("a avant :{%d}", (**a).head->data);
	test->data = max_chunk;
	printf("a apres :{%d}", (**a).head->data);
	return (0);
}

void	lsort(t_list **a, t_list **b)
{
	t_chunks	chunks;
	// t_node test;

	// test = *(*a)->head;
	// printf("a avant :{%d}", (*a)->head->data);
	// test.data = 12;
	// printf("a apres :{%d}", (*a)->head->data);
	(*b)->lenght = (*b)->lenght;
	init_chunk(&chunks, (*a)->lenght);
	find_smallest(a, chunks.q1);
}