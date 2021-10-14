/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcheckers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:38:38 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/14 16:23:37 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lcheck_sort(t_list **list)
{
	size_t	i;
	t_node	*iterator;

	i = 1;
	iterator = (*list)->head->next;
	if (list != NULL)
	{
		while (i < (*list)->lenght)
		{
			if (iterator->data < iterator->prev->data)
				return (1);
			iterator = iterator->next;
			i++;
		}
	}
	return (0);
}
