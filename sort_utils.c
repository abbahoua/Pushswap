/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:33:48 by abbahoua          #+#    #+#             */
/*   Updated: 2022/04/24 02:05:14 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_min(t_node *stack)
{
	int	nb;

	nb = (int) stack->index;
	while (stack)
	{
		if ((int) stack->index < nb)
			nb = (int) stack->index;
		stack = stack->link;
	}
	return (nb);
}

int	ft_index(t_node **stack)
{
	int		min;
	int		i;
	t_node	*n;

	i = 0;
	n = (*stack);
	min = ft_min(*stack);
	while (n)
	{
		if (n->index == min)
			return (i);
		n = n->link;
		i++;
	}
	return (i);
}

void	rotation_handler(t_node **stack_a, t_node **stack_b, \
		int rotation_number, int direction)
{
	if (direction == 0)
	{
		while (rotation_number > 0)
		{
			ra_rb(stack_a, 'a');
			rotation_number--;
		}
	}
	else
	{
		while (rotation_number > 0)
		{
			rra_rrb(stack_a, 'a');
			rotation_number--;
		}
	}
	ft_pb(stack_a, stack_b, 'b');
}

void	rotation_handler_b(t_node **stack_a, t_node **stack_b, \
		int rotation_number, int direction)
{
	if (direction == 0)
	{
		while (rotation_number > 0)
		{
			ra_rb(stack_b, 'b');
			rotation_number--;
		}
	}
	else
	{
		while (rotation_number > 0)
		{
			rra_rrb(stack_b, 'b');
			rotation_number--;
		}
	}
	ft_pa(stack_a, stack_b, 'a');
}
