/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:23:55 by abbahoua          #+#    #+#             */
/*   Updated: 2022/04/24 03:02:14 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sa_sb(t_node **stack, char c)
{
	int		temp;
	int		temp1;

	if (!stack || !(*stack) || !(*stack)->link)
		return ;
	temp = 0;
	if (ft_lstsize(*stack) == 1 || ft_lstsize(*stack) == 0)
		return ;
	else
	{
		temp = (*stack)->link->index;
		temp1 = (*stack)->link->data;
		(*stack)->link->index = (*stack)->index;
		(*stack)->link->data = (*stack)->data;
		(*stack)->index = temp;
		(*stack)->data = temp1;
	}
	if (c == 'a')
		ft_putstr("sa\n");
	else if (c == 'b')
		ft_putstr("sb\n");
}

void	ft_ss(t_node **stack_a, t_node **stack_b)
{
	ft_sa_sb(stack_a, 'p');
	ft_sa_sb(stack_b, 'p');
	ft_putstr("ss\n");
}

void	ft_pa(t_node **stack_a, t_node **stack_b, char c)
{
	t_node	*temp;

	if (!(*stack_b))
		return ;
	temp = (*stack_b);
	(*stack_b) = (*stack_b)->link;
	temp->link = NULL;
	ft_lstadd_front(stack_a, temp);
	if (c == 'a')
		ft_putstr("pa\n");
}

void	ft_pb(t_node **stack_a, t_node **stack_b, char c)
{
	t_node	*temp;

	if (!(*stack_a))
		return ;
	temp = (*stack_a);
	(*stack_a) = (*stack_a)->link;
	temp->link = NULL;
	ft_lstadd_front(stack_b, temp);
	if (c == 'b')
		ft_putstr("pb\n");
}

void	ft_rrasasb(t_node **stack)
{
	rra_rrb(stack, 'a');
	ft_sa_sb(stack, 'a');
}
