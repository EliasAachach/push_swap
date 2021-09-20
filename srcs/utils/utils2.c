/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:44:25 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/20 16:43:28 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write (1, str, ft_strlen(str));
}

void	set_stacks(int argc, char **argv, t_stack *stack)
{
	int i;

	i = 1;
	stack->a = (int *)malloc(sizeof(int) * (argc - 1));
	stack->b = (int *)malloc(sizeof(int) * (argc - 1));
	while (argv[i])
	{
		stack->a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}
