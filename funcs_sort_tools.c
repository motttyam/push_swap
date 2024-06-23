/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_sort_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:11:03 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 16:41:12 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int arrlen)
{
	int	i;
	int	j;
	int	temp;

	if (!arr)
	{
		write(1, "unexpected error in bubble_sort\n", 32);
		exit(1);
	}
	i = 0;
	while (i < arrlen - 1)
	{
		j = 0;
		while (j < arrlen - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	max_lim(t_stack *stack, int len)
{
	t_stack	*current;
	int		max;
	int		i;

	if (stack->next == stack)
		return (-1);
	current = stack->next;
	max = -1;
	i = 0;
	while (i++ < len)
	{
		if (max < current->num)
			max = current->num;
		current = current->next;
	}
	return (max);
}

int	min_lim(t_stack *stack, int len)
{
	t_stack	*current;
	int		min;
	int		i;

	if (stack->next == stack)
		return (-1);
	current = stack->next;
	min = INT_MAX;
	i = 0;
	while (i++ < len)
	{
		if (min > current->num)
			min = current->num;
		current = current->next;
	}
	return (min);
}

t_sort_params	init_params(t_stack **stack, int len, int i)
{
	t_sort_params	params;

	params.piv_h = ((max_lim(*stack, len) - min_lim(*stack, len) + 1) * 2 / 3)
		+ min_lim(*stack, len);
	params.piv_l = ((max_lim(*stack, len) - min_lim(*stack, len) + 1) / 3)
		+ min_lim(*stack, len);
	params.l = 0;
	params.m = 0;
	params.s = 0;
	params.i = i;
	return (params);
}
