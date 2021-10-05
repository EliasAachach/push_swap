/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lreverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:06:05 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/05 19:23:02 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lreverse(t_node *node, int move)
{
		if (node != NULL)
			node = node->prev;
		if (move == RR)
			printf("rrr\n");
		else if (move == RA)
		printf("rra\n");
		else if (move == RB)
		printf("rrb\n");
}
