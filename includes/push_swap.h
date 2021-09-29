/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:09:22 by elaachac          #+#    #+#             */
/*   Updated: 2021/09/29 15:40:14 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PA 0
# define PB 1
# define SA 0
# define SB 1
# define SS 2
# define RA 0
# define RB 1
# define RR 2
# define RRA 0
# define RRB 1
# define RRR 2

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
typedef	struct s_stack
{
	int	*a;
	int	*b;
	int	a_len;
	int	b_len;
	int	index_max_a;
	int	index_max_b;
	int	sub_index_a;
	int	sub_index_b;
}				t_stack;

typedef	struct s_node
{
	int				data;
	int				place;
	int				place_to_be;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;


typedef	struct s_list
{
	size_t	lenght;
	t_node	*head;
	t_node	*tail;
}				t_list;

int		error_prog(int ret);
int		ft_strchr(const char *str, char *c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strlen(char *s);
int		check_sort(t_stack *stack);
int		wich_pos(t_stack *stack, int num);
int		wich_case(t_stack *stack);
void	five_move(t_stack *stack, int pos);
void	check_args(int argc, char **argv);
void	set_stacks(int argc, char **argv, t_stack *stack);
void	choose_case(t_stack *stack);
void	ft_atoi_check(char *str);
void	ft_putstr(char *str);
void	rotate(t_stack *stack, int move);
void	reverse(t_stack *stack, int move);
void	push(t_stack *stack, int move);
void	swap(t_stack *stack, int move);
void	choose_case(t_stack *stack);
void	case_three(t_stack *stack);
void	dellist(t_list **list);
t_node	*add_tail_list(t_list *list, int data);
t_list	*newlist(int len);

#endif
