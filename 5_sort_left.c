/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sort_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:54:49 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 18:18:26 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_left(t_stack **a, t_stack **b, int len, t_sort_params *left)
{
	int	i;

	i = 0;
	while (i++ < len)
	{
		if ((*a)->next->num >= left->piv_h)
		{
			ra(a);
			left->l++;
		}
		else if ((*a)->next->num >= left->piv_l
			&& (*a)->next->num < left->piv_h)
		{
			pb(a, b);
			left->m++;
		}
		else if ((*a)->next->num < left->piv_l)
		{
			pb(a, b);
			rb(b);
			left->s++;
		}
	}
}

void	sort_left_lms(t_stack **a, t_stack **b, t_sort_params *left)
{
	int	i;

	i = 0;
	while (i++ < left->l)
		rra(a);
	sort_l_l(a, b, left->l);
	sort_l_m(a, b, left->m);
	sort_l_s(a, b, left->s);
}

void	sort_left(t_stack **a, t_stack **b, int len, int i)
{
	t_sort_params	left;

	left = init_params(a, len, i);
	if (len < 4)
		sort_l_l(a, b, len);
	if (len >= 4)
		partition_left(a, b, len, &left);
	if (left.l < 4)
		sort_left_lms(a, b, &left);
	else
	{
		i = 0;
		while (i++ < left.l && left.l != ft_lstsize(*a))
			rra(a);
		sort_left(a, b, left.l, 0);
		sort_right(a, b, left.m, 0);
		i = 0;
		while (i++ < left.s && left.s != ft_lstsize(*b))
			rrb(b);
		sort_right(a, b, left.s, 0);
	}
}
