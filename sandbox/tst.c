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
	int				chunk_pos;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef	struct s_list
{
	size_t	lenght;
	t_node	*head;
	t_node	*tail;
}				t_list;

static void		*ft_strfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return ((void *)0);
}

static int		ft_nbwrds(char const *s, char c)
{
	int	i;
	int	j;

	if (!s)
		return (-1);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (j);
}

static int		w(char const *s, int i, char c)
{
	while (s[i] != c && s[i])
		i++;
	return (i + 1);
}

char			**ft_split(char const *s, char c)
{
	char	**out;
	int		i[3];

	if ((ft_nbwrds(s, c) == -1)
			|| !(out = (char **)malloc(sizeof(char *) * (ft_nbwrds(s, c) + 1))))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (s[i[0]])
	{
		if (s[i[0]] != c)
		{
			if (!(out[i[1]] = (char *)malloc(sizeof(char) * w(s, i[0], c))))
				return (ft_strfree(out));
			i[2] = 0;
			while (s[i[0]] != c && s[i[0]])
				out[i[1]][i[2]++] = s[i[0]++];
			out[i[1]][i[2]] = '\0';
			i[1]++;
		}
		else
			i[0]++;
	}
	out[i[1]] = NULL;
	return (out);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	nb = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * neg);
}

void	init_node(t_node *node, int data)
{
	node->data = data;
	node->chunk_pos = -1;
}

t_node	*add_tail_list(t_list **list, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	if ((*list) != NULL)
	{
		if ((*list)->tail == NULL)
		{
			(*list)->head = newnode;
			(*list)->tail = newnode;
			newnode->prev = (*list)->head;
			newnode->next = (*list)->head;
		}
		else
		{
			(*list)->head->prev = newnode;
			(*list)->tail->next = newnode;
			newnode->next = (*list)->head;
			newnode->prev = (*list)->tail;
			(*list)->tail = newnode;
		}
		(*list)->lenght++;
	}
	init_node(newnode, data);
	return (newnode);
}

t_list	*newlist(void)
{
	t_list	*newlist;
	newlist = (t_list *)malloc(sizeof(*newlist));
	if (newlist == NULL)
		return (NULL);
	if (newlist != NULL)
	{
		newlist->lenght = 0;
		newlist->head = NULL;
		newlist->tail = NULL;
	}
	return (newlist);
}

void	init_list(char **argv, t_list **a, t_list **b)
{
	int i;
	int	j;
	char	**tmp;

	i = 1;
	*a = newlist();
	*b = newlist();
	while (argv[i])
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j] != NULL)
		{
			add_tail_list(a, ft_atoi(tmp[j++]));
			i++;
		}
	}
}

void	lswap(t_list **list, int move)
{
	t_node *tmp;
	
	tmp = (*list)->head;
	(*list)->head = (*list)->head->next;
	(*list)->head->next = tmp;
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	init_list(argv, &a, &b);
	printf("avant {%d}\n", a->head->data);
	lswap(&a, SA);
	printf("apres {%d}\n", a->head->data);
	printf("apres {%d}\n", a->head->next->data);
}
