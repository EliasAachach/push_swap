/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:27:18 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/30 16:52:43 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_chunk(t_chunks *chunks, size_t stack_len)
{
	chunks->q1 = (stack_len / 5) - 1;
	chunks->q2 = ;
	chunks->q3 = ;
	chunks->q4 = ;
	chunks->q5 = ;
	if (stack_len < 500)
	{
		chunks->q6 = 0;
		chunks->q7 = 0;
		chunks->q8 = 0;
		chunks->q9 = 0;
		chunks->q10 = 0;
		chunks->q11 = 0;
	}

}

void	lsort(t_list **a, t_list **b)
{
	t_chunks chunks;

	init_chunk(&chunks, (*a)->lenght);
}