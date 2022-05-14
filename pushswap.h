/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:59:33 by abbahoua          #+#    #+#             */
/*   Updated: 2022/05/09 15:16:06 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>

# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*link;
}	t_node;

typedef struct variables
{
	int	size;
	int	max;
	int	mid;
	int	min;
	int	to_push;
	int	rc;
}		t_var;

int		ft_isdigit(int c);
int		ft_atoi(char *str);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int content);
int		ft_lstsize(t_node *lst);
void	no_duplicate(char *s1, char *s2);
void	swap_a(t_node **stack_a);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_rrb(t_node **head);
void	ft_error(void);
void	ft_sa_sb(t_node **stack, char c);
void	ft_ss(t_node **stack_a, t_node **stack_b);
void	ft_pa(t_node **stack_a, t_node **stack_b, char c);
void	ft_pb(t_node **stack_a, t_node **stack_b, char c);
void	ra_rb(t_node **stack, char c);
void	rra_rrb(t_node **stack, char c);
void	ft_rr(t_node **stack);
void	ft_rrr(t_node **stack);
void	sort_two(t_node **stack);
void	sort_two(t_node **stack);
void	sort_three(t_node **stack);
int		ft_min(t_node *stack);
void	ft_rarb(t_node **stack, char a);
void	ft_rrasasb(t_node **stack);
void	ft_sasbrra(t_node **stack);
int		ft_index(t_node **stack);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_three_pa(t_node **stack, t_node **stackb);
int		*sort_array(int *array, int size);
int		*stack_to_array(t_node **stack, int *array, int size);
int		find_index(int data, int *array, int size);
void	index_stack(t_node **stack, int size);
int		check_double(t_node	**stack);
void	create_stack(int ac, char **av, t_node **stack);
int		check_sorting(t_node **stack);
void	sorting_algo(t_node **stack_a, t_node **stack_b, int ac);
void	rotation_handler(t_node **stack_a, t_node **stack_b, \
		int rotation_number, int direction);
void	a_to_b(t_node **stack_a, t_node **stack_b, t_var *var);
void	sort_more(t_node **stack_a, t_node **stack_b);
int		find_node(t_node *stack, int index);
void	b_to_a(t_node **stack_a, t_node **stack_b);
void	rotation_handler_b(t_node **stack_a, t_node **stack_b, \
		int rotation_number, int direction);
void	find_push(t_node **stack_a, t_node **stack_b, int size, int index);
void	check_str(char *str);
void	zero_top(t_node	**stack);
void	a_b_norm(t_node **stack_a, t_node **stack_b, t_var *var, t_node *tmp);
void	b_a_norm(t_node **stack_a, t_node **stack_b);
void	last_index(t_node **stack);
int		sign_issue(char *str);
void	ft_rrasasb(t_node **stack);
void	ft_sasbrra(t_node **stack);
int		dbquoates(char **av, int ac);
void	double_quoates(int ac, char **av, t_node *node, t_node **stack);
void	no_leaks(t_node **stack);
char	*get_next_line(int fd);
void	arg_count(char **s);

#endif