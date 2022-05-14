/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:22:53 by abbahoua          #+#    #+#             */
/*   Updated: 2022/04/24 02:06:23 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two(t_node **stack)
{
	if ((*stack)->link->data < (*stack)->data)
		ft_sa_sb(stack, 'a');
}

void	sort_three(t_node **stack)
{
	t_node	*p;

	p = (*stack);
	if (p->index < p->link->index && p->link->index < p->link->link->index)
		return ;
	else if (p->index > p->link->index && p->link->index < p->link->link->index)
	{
		if (p->index > p->link->link->index)
			ra_rb(stack, 'a');
		else
			ft_sa_sb(stack, 'a');
	}
	else if (p->index < p->link->index && p->link->index < p->link->link->index)
		ft_rrasasb(stack);
	else if (p->index < p->link->index && p->link->index > p->link->link->index)
	{
		if (p->index < p->link->link->index)
			ft_rrasasb(stack);
		else
			rra_rrb(stack, 'a');
	}
	else if (p->index > p->link->index && p->link->index > p->link->link->index)
		ft_sasbrra(stack);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	index;
	int	min;
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = 1;
	while (i--)
	{
		min = ft_min(*stack_a);
		index = ft_index(stack_a);
		if (index > (size / 2))
			rotation_handler(stack_a, stack_b, (size - index), 1);
		else
			rotation_handler(stack_a, stack_b, index, 0);
		size--;
	}
	sort_three(stack_a);
	ft_pa(stack_a, stack_b, 'a');
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	index;
	int	min;
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = 2;
	while (i--)
	{
		min = ft_min(*stack_a);
		index = ft_index(stack_a);
		if (index > (size / 2))
			rotation_handler(stack_a, stack_b, (size - index), 1);
		else
			rotation_handler(stack_a, stack_b, index, 0);
		size--;
	}
	sort_three_pa(stack_a, stack_b);
}

void	sort_three_pa(t_node **stack, t_node **stackb)
{
	sort_three(stack);
	ft_pa(stack, stackb, 'a');
	ft_pa(stack, stackb, 'a');
}
