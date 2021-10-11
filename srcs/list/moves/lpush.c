/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:39:03 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/08 11:30:54 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*del_element_top(t_node *head)
{
	t_node	*tmp;

	tmp = NULL;
	if (head->next == head)
	{
		free(head);
		head = NULL;
	}
	else
	{
		tmp = head;
		head = tmp->next;
		tmp->prev->next = head;
		head->prev = tmp->prev;
		free(tmp);
	}
	return (head);
}

void	lpush(t_list **a, t_list **b, int move)
{
	int tmp;

	if (move == PA)
	{
		tmp = (*b)->head->data;
		(*b)->head = del_element_top((*b)->head);
		(*a)->head = add_head_list(a, tmp);
		printf("pa\n");
	}
	else if (move == PB)
	{
		tmp = (*a)->head->data;
		(*a)->head = del_element_top((*a)->head);
		(*b)->head = add_head_list(b, tmp);
		printf("pb\n");
	}
}