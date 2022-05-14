/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:07:42 by abbahoua          #+#    #+#             */
/*   Updated: 2022/05/09 15:17:34 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	arg_count(char **s)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			j++;
			count++;
		}
		if (count > 11)
			ft_error();
		count = 0;
		i++;
	}
}

int	*stack_to_array(t_node **stack, int *array, int size)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = (*stack);
	while (temp)
	{
		array[i] = temp->data;
		temp = temp->link;
		i++;
	}
	sort_array(array, size);
	return (array);
}

void	create_stack(int ac, char **av, t_node **stack)
{
	t_node	*node;

	while (ac > 1)
	{
		if (dbquoates(av, ac - 1))
			double_quoates(ac, av, node, stack);
		else
		{
			node = ft_lstnew(ft_atoi(av[ac - 1]));
			ft_lstadd_front(stack, node);
		}
		ac--;
	}
}

void	index_stack(t_node **stack, int size)
{
	int		i;
	int		*array;
	t_node	*temp;

	array = malloc(sizeof(int) * size);
	if (!array)
		return ;
	array = stack_to_array(stack, array, size);
	i = 0;
	temp = (*stack);
	while (temp)
	{
		temp->index = find_index(temp->data, array, size);
		temp = temp->link;
	}
	free(array);
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	swp;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				swp = array[i];
				array[i] = array[j];
				array[j] = swp;
			}
			++j;
		}
		++i;
	}
	return (array);
}
