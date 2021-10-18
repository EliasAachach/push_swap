/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:39:03 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/18 15:00:44 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*del_element_top(t_node *head, t_list **list)
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
	(*list)->lenght--;
	return (head);
}

void	lpush(t_list **a, t_list **b, int move)
{
	int	tmp;

	if (move == PA)
	{
		tmp = (*b)->head->data;
		(*b)->head = del_element_top((*b)->head, b);
		(*a)->head = add_head_list(a, tmp);
		ft_putstr("pa\n");
		if ((*b)->lenght == 0)
			(*b)->tail = NULL;
	}
	else if (move == PB)
	{
		tmp = (*a)->head->data;
		(*a)->head = del_element_top((*a)->head, a);
		(*b)->head = add_head_list(b, tmp);
		ft_putstr("pb\n");
		if ((*a)->lenght == 0)
			(*a)->tail = NULL;
	}
}
