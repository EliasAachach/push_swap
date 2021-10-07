/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:46:31 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/07 16:49:01 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lreverse(t_list **list, int move)
{
	(*list)->head = (*list)->head->next;
	(*list)->tail = (*list)->tail->next;
	if (move == RRR)
		printf("rrr\n");
	else if (move == RRA)
		printf("rra\n");
	else if (move == RRB)
		printf("rrb\n");
}
void	lrotate(t_list **list, int move)
{
	(*list)->head = (*list)->head->prev;
	(*list)->tail = (*list)->tail->prev;
	if (move == RR)
		printf("rr\n");
	else if (move == RA)
		printf("ra\n");
	else if (move == RB)
		printf("rb\n");
}