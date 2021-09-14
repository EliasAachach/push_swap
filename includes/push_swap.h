/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:09:22 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/14 18:03:42 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef	struct s_stack
{
	int	*a;
	int	*b;
	int	index_max_a;
	int	index_max_b;
	int	sub_index_a;
	int	sub_index_b;
}				t_stack;


void	ft_atoi_check(char *str);
int		error_prog(int ret);
int		ft_strchr(const char *str, char *c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strlen(char *s);
void	check_args(int argc, char **argv);
void	set_stacks(int argc, char **argv, t_stack *stack);
void	choose_case(t_stack *stack);
int		check_sort(int *stack);
