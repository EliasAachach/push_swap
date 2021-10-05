/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:46:31 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/05 18:05:47 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lrotate(t_node *node, int move)
{
	if (move == RA || move == RR)
	{
		if (node != NULL)
			node = node->next;
		if (move == RR)
			printf("rr\n");
		else
		printf("ra\n");
	}
	else if (move == RB || move == RR)
	{
		if (node != NULL)
			node = node->next;
		if (move == RR)
			printf("rr\n");
		else
		printf("ra\n");
	}
}