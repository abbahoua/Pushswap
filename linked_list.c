/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:20:01 by abbahoua          #+#    #+#             */
/*   Updated: 2022/04/14 02:50:24 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (lst)
	{
		if (*lst)
			new->link = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->link = new;
		}
		else
			*lst = new;
	}
}

t_node	*ft_lstlast(t_node *lst)
{
	if (lst)
	{
		while (lst != 0)
		{
			if (lst->link == NULL)
				return (lst);
			lst = lst->link;
		}
		return (lst);
	}
	return (NULL);
}

t_node	*ft_lstnew(int content)
{
	t_node	*head;

	head = malloc(sizeof (t_node));
	if (!head)
		return (NULL);
	head->data = content;
	head->link = NULL;
	return (head);
}

int	ft_lstsize(t_node *lst)
{
	int		size;
	t_node	*ptr;

	if (!lst)
		return (0);
	ptr = lst;
	size = 0;
	while (ptr != NULL)
	{
		size++;
		ptr = ptr->link;
	}
	return (size);
}
