/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:44:25 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/18 15:13:14 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest(t_list **a, int *pos)
{
	size_t	count;
	t_node	*iter_node;
	t_node	*smallest_node;

	count = 0;
	iter_node = (*a)->head;
	smallest_node = iter_node;
	while (smallest_node->chunk_pos != -1 && smallest_node->next != (*a)->head)
		smallest_node = smallest_node->next;
	while (count < (*a)->lenght)
	{
		iter_node = iter_node->next;
		if (smallest_node->data > iter_node->data && iter_node->chunk_pos == -1)
		{
			smallest_node = iter_node;
			iter_node = (*a)->head;
			*pos = (int)count;
			count = 0;
		}
		else
			count++;
	}
	return (smallest_node);
}

void	free_split(char **array)
{
	int	i;

	i = 0;
	if (array && *array)
	{
		while (array[i] != NULL)
		{
			if (array[i])
				free(array[i]);
			i++;
		}
	}
	free(array);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write (1, str, ft_strlen(str));
}
