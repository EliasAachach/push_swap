/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:38:22 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/30 15:24:46 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*newlist(void)
{
	t_list	*newlist;
	newlist = (t_list *)malloc(sizeof(*newlist));
	if (newlist == NULL)
		return (NULL);
	if (newlist != NULL)
	{
		newlist->lenght = 0;
		newlist->head = NULL;
		newlist->tail = NULL;
	}
	return (newlist);
}

void	dellist(t_list **list)
{
	t_node	*tmp;
	t_node	*del;

	if (list != NULL)
	{
		tmp = (*list)->head;
		while ((*list)->lenght)
		{
			(*list)->lenght--;
			del = tmp;
			tmp = tmp->next;
			free(del);
		}
		free(*list);
		*list = NULL;
	}
}

void	init_node(t_node *node, int data, int pos, int chunk)
{
	node->data = data;
	node->chunk_pos = chunk;
	node->pos = pos;
}

t_node	*add_tail_list(t_list **list, int data, int chunk)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	if ((*list) != NULL)
	{
		if ((*list)->tail == NULL)
		{
			(*list)->head = newnode;
			(*list)->tail = newnode;
			newnode->prev = (*list)->head;
			newnode->next = (*list)->head;
		}
		else
		{
			(*list)->tail->next = newnode;
			newnode->next = (*list)->head;
			newnode->prev = (*list)->tail;
			(*list)->tail = newnode;
		}
		(*list)->lenght++;
	}
	init_node(newnode, data, (*list)->lenght - 1, chunk);
	return (newnode);
}
