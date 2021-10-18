/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:46:31 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/18 15:00:00 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lreverse(t_list **list, int move)
{
	(*list)->head = (*list)->head->prev;
	(*list)->tail = (*list)->tail->prev;
	if (move == RRR)
		ft_putstr("rrr\n");
	else if (move == RRA)
		ft_putstr("rra\n");
	else if (move == RRB)
		ft_putstr("rrb\n");
}

void	lrotate(t_list **list, int move)
{
	(*list)->head = (*list)->head->next;
	(*list)->tail = (*list)->tail->next;
	if (move == RR)
		ft_putstr("rr\n");
	else if (move == RA)
		ft_putstr("ra\n");
	else if (move == RB)
		ft_putstr("rb\n");
}
