/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:27:18 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/01 12:07:14 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_500
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

void	lsort(t_list **a, t_list **b)
{
	t_chunks chunks;

	init_chunk(&chunks, (*a)->lenght);
}