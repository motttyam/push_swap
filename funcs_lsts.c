/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_lsts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:18:28 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 18:37:05 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = content;
	new->next = new;
	new->previous = new;
	return (new);
}

void	ft_lstadd_back(t_stack **list, t_stack *new)
{
	t_stack	*last;

	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
	}
	else
	{
		last = (*list)->previous;
		last->next = new;
		new->previous = last;
		new->next = *(list);
		(*list)->previous = new;
	}
}

t_stack	*ft_lstlast(t_stack *list)
{
	if (!list)
		return (NULL);
	return (list->previous);
}

int	ft_lstsize(t_stack *list)
{
	int	length;

	length = 0;
	while (list->next->num >= 0)
	{
		list = list->next;
		length++;
	}
	return (length);
}

void	ft_lstclear(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*last;

	if (!a || !(*a))
		return ;
	current = *a;
	last = (*a)->previous;
	while (current != last)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
	free(*b);
	(*a) = NULL;
	(*b) = NULL;
}
