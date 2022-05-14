/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:02:30 by abbahoua          #+#    #+#             */
/*   Updated: 2022/05/09 15:16:44 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	find_index(int data, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == data)
			return (i);
		i++;
	}
	return (i);
}

void	double_quoates(int ac, char **av, t_node *node, t_node **stack)
{
	int		k;
	int		i;
	char	**arr;

	k = 0;
	if (dbquoates(av, ac - 1))
	{
		arr = ft_split(av[ac - 1], ' ');
		k = ft_sstrlen(arr);
		while (k > 0)
		{
			node = ft_lstnew(ft_atoi(arr[k - 1]));
			ft_lstadd_front(stack, node);
			k--;
		}
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	print_stack(t_node *stack)
{
	t_node	*tmp;

	tmp = (stack);
	while (stack)
	{
		printf ("|%d|\n", stack->index);
		stack = stack->link;
	}
}

void	sorting_algo(t_node **stack_a, t_node **stack_b, int ac)
{
	if (ac == 2)
		sort_two(stack_a);
	else if (ac == 3)
		sort_three(stack_a);
	else if (ac == 4)
		sort_four(stack_a, stack_b);
	else if (ac == 5)
		sort_five(stack_a, stack_b);
	else if (ac > 5)
		sort_more(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = 0;
	stack_b = 0;
	arg_count(av);
	create_stack(ac, av, &stack_a);
	index_stack(&stack_a, ft_lstsize(stack_a));
	if (ac == 1)
		return (0);
	else if (ac > 1)
	{
		if (!check_double(&stack_a))
		{
			if (!check_sorting(&stack_a))
				sorting_algo(&stack_a, &stack_b, ft_lstsize(stack_a));
		}
		else
			return (0);
	}
	else
		ft_error();
	no_leaks(&stack_a);
	return (0);
}
