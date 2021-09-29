/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:38:22 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/29 15:40:01 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*newlist(int len)
{
	t_list	*newlist;
	newlist = (t_list *)malloc(sizeof(*newlist));
	if (newlist == NULL)
		return (NULL);
	if (newlist != NULL)
	{
		newlist->lenght = len;
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
		while (tmp != NULL)
		{
			del = tmp;
			tmp = tmp->next;
			free(del);
		}
		free(*list);
		*list = NULL;
	}
}

t_node	*add_tail_list(t_list *list, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	if (list != NULL)
	{
		if (list->tail == NULL)
		{
			list->head = newnode;
			list->tail = newnode;
			newnode->prev = list->head;
			newnode->next = list->head;
		}
		else
		{
			list->tail->next = newnode;
			newnode->next = list->head;
			newnode->prev = list->tail;
			list->tail = newnode;
		}
		newnode->data = data;
		list->lenght++;
	}
	return (newnode);
}
