/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_print_rotate_reverse.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:15:13 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/06 23:30:09 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rra(t_stack **a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
}
