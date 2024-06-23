/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:27:40 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 21:25:14 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnum(char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
	{
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		else
			str++;
	}
	return (1);
}

int	is_unique_num(int *arr, int arrlen)
{
	int	i;
	int	j;

	if (!arr)
	{
		write(1, "unexpected error in is_unique_num\n", 34);
		exit(1);
	}
	i = 0;
	while (i < arrlen)
	{
		j = i + 1;
		while (j < arrlen)
		{
			if (arr[i] == arr[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a->next;
	while (current->next != stack_a)
	{
		if (current->num > current->next->num)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}
