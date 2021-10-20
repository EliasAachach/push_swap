/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:23:32 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/20 15:19:47 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char *char_nbr)
{
	int	i;

	i = 0;
	while (char_nbr[i])
	{
		if (ft_isdigit(char_nbr[i]) == 0)
			error_prog(0);
		i++;
	}
}

int	dup_check( char **list, char *nbr, int imax)
{
	int	i;
	int	int_nbr;

	i = 1;
	int_nbr = ft_atoi(nbr);
	while (i < imax)
	{
		if (int_nbr == ft_atoi(list[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		error_prog(0);
	while (argv[i])
	{
		check_int(argv[i]);
		if (dup_check(argv, argv[i], i) == 1)
			error_prog(0);
		i++;
	}	
}
