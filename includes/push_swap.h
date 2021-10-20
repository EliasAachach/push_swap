/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:09:22 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/20 16:08:18 by elaachac         ###   ########.fr       */
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

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				chunk_pos;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_list
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
int		wich_case(t_list **a);
int		lcheck_sort(t_list **list);
int		ft_atoi_check(char *str);
void	check_args(int argc, char **argv);
void	ft_putstr(char *str);
char	**ft_split(char const *s, char c);
void	choose_case(t_list **a, t_list **b);
void	case_three(t_list **a);
void	dellist(t_list **list);
void	lsort(t_list **a, t_list **b);
void	lreverse(t_list **list, int move);
void	lpush(t_list **a, t_list **b, int move);
void	lpush(t_list **a, t_list **b, int move);
void	lrotate(t_list **list, int move);
void	lswap(t_list **list, int move);
void	free_split(char **array);
t_node	*add_tail_list(t_list **list, int data);
t_node	*add_head_list(t_list **list, int data);
t_node	*find_highest(t_list **a, int *wich_count);
t_node	*find_smallest(t_list **a, int *pos);
t_list	*newlist(void);

#endif
