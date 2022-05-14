/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:25:16 by abbahoua          #+#    #+#             */
/*   Updated: 2022/04/23 03:50:06 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra_rb(t_node **stack, char a)
{
	t_node	*temp;
	t_node	*head;

	if (!stack || !(*stack) || !(*stack)->link)
		return ;
	temp = *stack;
	head = (*stack)->link;
	while (temp->link)
		temp = temp->link;
	temp->link = *stack;
	(*stack)->link = NULL;
	*stack = head;
	if (a == 'a')
		write(1, "ra\n", 3);
	else if (a == 'b')
		write(1, "rb\n", 3);
}

void	rra_rrb(t_node **stack, char c)
{
	t_node	*temp;
	t_node	*first;

	if (!stack || !(*stack))
		return ;
	first = (*stack);
	while (first->link->link)
		first = first->link;
	temp = first->link;
	first->link = NULL;
	ft_lstadd_front(stack, temp);
	if (c == 'a')
		ft_putstr("rra\n");
	else if (c == 'b')
		ft_putstr("rrb\n");
}

void	ft_rr(t_node **stack)
{
	ra_rb(stack, 'a');
	ra_rb(stack, 'b');
	ft_putstr("rr\n");
}

void	ft_rrr(t_node **stack)
{
	rra_rrb(stack, 'a');
	rra_rrb(stack, 'b');
	ft_putstr("rrr\n");
}

void	ft_sasbrra(t_node **stack)
{
	ft_sa_sb(stack, 'a');
	rra_rrb(stack, 'a');
}
