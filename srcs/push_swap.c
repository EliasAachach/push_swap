/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:56:10 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/10 16:20:04 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	check_int(char *char_nbr)
{
	int i;

	i = 0;
	ft_atoi_check(char_nbr);
	while (char_nbr[i])
	{
		if (ft_isdigit(char_nbr[i]) == 0)
			error_prog(0);
			i++;
	}
}

int	dup_check( char **list, char *nbr, int imax)
{
	int i;
	int int_nbr;

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
	int i;

	i = 1;
	if (argc <= 2)
		error_prog(0);
	while (argv[i])
	{
		check_int(argv[i]);
		if (dup_check(argv, argv[i], i) == 1)
			error_prog(0);
		i++;
	}
	
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
}