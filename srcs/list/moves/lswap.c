/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:30:27 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/18 15:00:25 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lswap(t_list **list, int move)
{
	t_node	*tmp;
	int		data_tmp;

	tmp = (*list)->head->next;
	data_tmp = tmp->data;
	tmp->data = (*list)->head->data;
	(*list)->head->data = data_tmp;
	if (move == SA)
		ft_putstr("sa\n");
	else if (move == SB)
		ft_putstr("sb\n");
	else if (move == SS)
		ft_putstr("ss\n");
}
