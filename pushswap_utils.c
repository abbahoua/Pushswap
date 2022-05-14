/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:42:06 by abbahoua          #+#    #+#             */
/*   Updated: 2022/04/24 03:19:14 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	sign_issue(char *str)
{
	int	i;

	if (!str)
		return (2);
	i = 0;
	while (str[i])
	{
		if ((str[0] == '+') || (str[0] == '-')
			|| (str[0] >= '0' && str[0] <= '9'))
		{
			if (str[0] == '+' || str[0] == '-')
			{
				if (str[1] >= '0' && str[1] <= '9')
					return (1);
				else if (str[0] >= '0' && str[0] <= '9')
					return (1);
				else
					ft_error();
			}	
		}
		else
			ft_error();
		i++;
	}
	return (0);
}

void	check_str(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error();
		i++;
	}
}

int	check_double(t_node	**stack)
{
	t_node	*first;
	t_node	*second;

	first = (*stack);
	while (first)
	{
		second = first->link;
		while (second)
		{
			if (first->data == second->data)
				ft_error();
			second = second->link;
		}
		first = first->link;
	}
	return (0);
}

int	check_sorting(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = (*stack);
	second = (*stack)->link;
	while (first)
	{
		while (second)
		{
			if (first->index > second->index)
				return (0);
			second = second->link;
		}
		second = first->link;
		first = first->link;
	}
	return (1);
}
