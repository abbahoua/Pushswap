/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:03:44 by abbahoua          #+#    #+#             */
/*   Updated: 2022/04/23 22:57:16 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	last_index(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack);
	while (tmp->link->link)
		tmp = tmp->link;
	tmp->link->index = tmp->index + 1;
}

int	find_node(t_node *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		stack = stack->link;
		i++;
	}
	return (-1);
}

void	find_push(t_node **stack_a, t_node **stack_b, int size, int index)
{
	int	one_time;
	int	find_index;

	one_time = 1;
	while (one_time)
	{
		find_index = find_node(*stack_b, index);
		if (find_index > size / 2)
			rotation_handler_b(stack_a, stack_b, (size - find_index), 1);
		else
			rotation_handler_b(stack_a, stack_b, find_index, 0);
		one_time--;
	}
}

void	zero_top(t_node **stack_a)
{
	t_node	*tmp_a;

	tmp_a = (*stack_a);
	while (tmp_a)
	{
		if ((*stack_a)->index != 0)
			rra_rrb(stack_a, 'a');
		else
			break ;
		tmp_a = tmp_a->link;
	}
}

void	no_leaks(t_node **stack)
{
	while ((*stack))
	{
		free(*stack);
		*stack = (*stack)->link;
	}
}
