/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_p_s_r_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:41:06 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 12:58:19 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int		temp;
	t_stack	*top_node;

	if (!stack || stack->next == stack || stack->next->next == stack)
	{
		return ;
	}
	top_node = stack->next;
	temp = top_node->num;
	top_node->num = top_node->next->num;
	top_node->next->num = temp;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*top_src;

	if (!src || !*src || (*src)->next == (*src) || !dst || !*dst)
	{
		return ;
	}
	top_src = (*src)->next;
	top_src->next->previous = (*src);
	(*src)->next = top_src->next;
	(*dst)->next->previous = top_src;
	top_src->next = (*dst)->next;
	top_src->previous = (*dst);
	(*dst)->next = top_src;
}

void	rotate(t_stack **stack)
{
	t_stack	*top_node;
	t_stack	*last_node;

	if (!stack || !*stack || (*stack)->next == (*stack)
		|| (*stack)->next->next == (*stack))
		return ;
	top_node = (*stack)->next;
	last_node = (*stack)->previous;
	(*stack)->next = top_node->next;
	top_node->next->previous = (*stack);
	top_node->next = (*stack);
	(*stack)->previous = top_node;
	last_node->next = top_node;
	top_node->previous = last_node;
}

void	r_rotate(t_stack **stack)
{
	t_stack	*top_node;
	t_stack	*last_node;

	if (!stack || !*stack || (*stack)->next == (*stack)
		|| (*stack)->next->next == (*stack))
		return ;
	top_node = (*stack)->next;
	last_node = (*stack)->previous;
	last_node->previous->next = (*stack);
	(*stack)->previous = last_node->previous;
	last_node->previous = (*stack);
	(*stack)->next = last_node;
	top_node->previous = last_node;
	last_node->next = top_node;
}
