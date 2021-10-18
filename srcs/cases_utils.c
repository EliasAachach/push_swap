/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:31:39 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/18 14:30:37 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	wich_case(t_list **a)
{
	if (((*a)->head->data > (*a)->head->next->data \
		&& (*a)->head->data < (*a)->tail->data))
		return (1);
	if (((*a)->head->data > (*a)->head->next->data \
		&& (*a)->head->data > (*a)->tail->data) && \
		((*a)->head->next->data > (*a)->tail->data))
		return (2);
	if (((*a)->head->data > (*a)->head->next->data \
		&& (*a)->head->data > (*a)->tail->data) && \
		((*a)->head->next->data < (*a)->tail->data))
		return (3);
	if (((*a)->head->data < (*a)->head->next->data && \
		(*a)->head->data < (*a)->tail->data))
		return (4);
	if (((*a)->head->data < (*a)->head->next->data && \
		(*a)->head->data > (*a)->tail->data))
		return (5);
	return (0);
}
