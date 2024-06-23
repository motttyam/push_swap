/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:25:23 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/06 23:30:28 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	len = ft_lstsize(stack_a);
	if (len < 6)
	{
		sort_few(stack_a, stack_b);
	}
	else
	{
		if (is_sorted(stack_a) && stack_b->next == stack_b)
			return ;
		else
			sort_left(&stack_a, &stack_b, len, 0);
	}
}
