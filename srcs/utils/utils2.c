/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:44:25 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/13 18:08:13 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **array)
{
	int	i;

	i = 0;
	if (array && *array)
		while (array[i] != NULL)
		{
			if (array[i])
				free(array[i]);
			i++;
		}
	free(array);
}

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
	int	j;
	char	**tmp;

	i = 1;
	stack->a = (int *)malloc(sizeof(int) * (argc - 1));
	stack->b = (int *)malloc(sizeof(int) * (argc - 1));
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		printf("{%s}\n", *tmp);
		j = 0;
		while (tmp[j] != NULL)
		{
			stack->a[i - 1] = ft_atoi(tmp[j++]);
			i++;
		}
		free_split(tmp);
	}
}
