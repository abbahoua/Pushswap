/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:45:35 by abbahoua          #+#    #+#             */
/*   Updated: 2022/04/24 02:04:11 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_more(t_node **stack_a, t_node **stack_b)
{
	t_var	var;

	var.size = ft_lstsize(*stack_a);
	while (var.size > 5)
	{
		var.min = ft_min(*stack_a);
		var.to_push = (var.size - 5) / 3 + 1;
		var.max = (var.to_push + var.min) - 1;
		var.mid = (var.max + var.min) / 2;
		a_to_b(stack_a, stack_b, &var);
	}
	sort_five(stack_a, stack_b);
	ft_lstlast(*stack_a)->index = -1;
	b_to_a(stack_a, stack_b);
}

void	a_to_b(t_node **stack_a, t_node **stack_b, t_var *var)
{
	int		push;
	int		rotation;
	t_node	*tmp;

	push = var->to_push;
	rotation = 0;
	tmp = (*stack_a);
	while (push > 0)
	{
		var->rc = rotation;
		if (var->min <= tmp->index && tmp->index <= var->max)
		{
			a_b_norm(stack_a, stack_b, var, tmp);
			tmp = (*stack_a);
			rotation = 0;
			push--;
			var->size--;
		}
		else
		{
			rotation++;
			tmp = tmp->link;
		}
	}
}

void	a_b_norm(t_node **stack_a, t_node **stack_b, t_var *var, t_node *tmp)
{
	if (var->min <= tmp->index && tmp->index <= var->max)
	{
		if (var->rc > (var->size / 2))
			rotation_handler(stack_a, stack_b, (var->size - var->rc), 1);
		else
			rotation_handler(stack_a, stack_b, var->rc, 0);
		if ((*stack_b)->index > var->mid)
			ra_rb(stack_b, 'b');
	}
}

void	b_a_norm(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = 0;
	while ((*stack_b))
	{
		size = ft_lstsize(*stack_b);
		if (((*stack_a)->index - 1) == (*stack_b)->index)
			ft_pa(stack_a, stack_b, 'a');
		else if (find_node(*stack_b, (*stack_a)->index - 1) != -1)
		{
			if ((*stack_b)->index <= (*stack_a)->index - 1
				&& (*stack_b)->index >= ft_lstlast(*stack_a)->index)
			{
				ft_pa(stack_a, stack_b, 'a');
				ra_rb(stack_a, 'a');
			}
			else
			{
				find_push(stack_a, stack_b, size, (*stack_a)->index - 1);
			}
		}
		else
			rra_rrb(stack_a, 'a');
	}
}

void	b_to_a(t_node **stack_a, t_node **stack_b)
{
	b_a_norm(stack_a, stack_b);
	zero_top(stack_a);
	last_index(stack_a);
}
