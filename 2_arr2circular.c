/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_arr2circular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:07:05 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 21:12:07 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*arr2circular(int *arr, int arrlen)
{
	int	*cp_arr;

	if (!is_unique_num(arr, arrlen))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	cp_arr = arrcpy(arr, arrlen);
	arr_value2compact_range(arr, cp_arr, arrlen);
	return (free(cp_arr), arr_value2circular(arr, arrlen));
}

t_stack	*arr_value2circular(int *arr, int arrlen)
{
	int		i;
	t_stack	*list;
	t_stack	*newnode;

	if (!arr)
		exit(1);
	i = 0;
	list = NULL;
	while (i < arrlen)
	{
		newnode = ft_lstnew(arr[i]);
		if (!newnode)
		{
			write(1, "malloc error at ft_lstnew\n", 27);
			exit(1);
		}
		ft_lstadd_back(&list, newnode);
		i++;
	}
	if (list)
		return (link2circular(list), list->previous);
	return (NULL);
}

void	link2circular(t_stack *list)
{
	t_stack	*newnode;
	t_stack	*last;

	newnode = ft_lstnew(-1);
	last = ft_lstlast(list);
	newnode->next = list;
	list->previous = newnode;
	newnode->previous = last;
	last->next = newnode;
}

void	arr_value2compact_range(int *arr, int *cp_arr, int arrlen)
{
	int	i;
	int	j;

	if (!arr || !cp_arr)
		exit(1);
	bubble_sort(cp_arr, arrlen);
	i = 0;
	while (i < arrlen)
	{
		j = 0;
		while (j < arrlen)
		{
			if (cp_arr[i] == arr[j])
			{
				arr[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}
