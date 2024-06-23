/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:24:04 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/07 00:15:36 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	if (stack->next == stack)
	{
		printf("Stack is empty\n");
		return ;
	}
	current = stack->next;
	printf("Stack: ");
	while (current != stack)
	{
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");
}
