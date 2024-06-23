/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sort_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:39:55 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 18:19:02 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_right(t_stack **a, t_stack **b, int len, int i)
{
	t_sort_params	right;

	right = init_params(b, len, i);
	if (len >= 4)
		partition_right(a, b, &right, len);
	if (right.s == 0 && right.m == 0 && right.l == 0)
	{
		sort_r_s(a, b, len);
		return ;
	}
	else if (right.s < 4)
		sort_right_lms(a, b, &right);
	else
	{
		sort_left(a, b, right.l, 0);
		i = 0;
		while (i++ < right.m)
			rra(a);
		sort_left(a, b, right.m, 0);
		i = 0;
		while (i++ < right.s)
			rrb(b);
		sort_right(a, b, right.s, 0);
	}
}

void	partition_right(t_stack **a, t_stack **b, t_sort_params *right, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
	{
		if ((*b)->next->num > right->piv_h)
		{
			pa(a, b);
			right->l++;
		}
		else if ((*b)->next->num > right->piv_l
			&& (*b)->next->num <= right->piv_h)
		{
			pa(a, b);
			ra(a);
			right->m++;
		}
		else if ((*b)->next->num <= right->piv_l)
		{
			rb(b);
			right->s++;
		}
	}
}

void	sort_right_lms(t_stack **a, t_stack **b, t_sort_params *right)
{
	int	i;

	i = 0;
	sort_r_l(a, b, right->l);
	sort_r_m(a, b, right->m);
	while (i++ < right->s)
		rrb(b);
	sort_r_s(a, b, right->s);
}
