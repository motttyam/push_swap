/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_sort_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:37:20 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/07 00:37:34 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_r_s(t_stack **a, t_stack **b, int len)
{
	t_position	pos;

	pos.top = (*b)->next->num;
	pos.mid = (*b)->next->next->num;
	pos.last = (*b)->next->next->next->num;
	if (len == 1)
		pa(a, b);
	else if (len == 2)
	{
		if (pos.top < pos.mid)
			return (sb(b), pa(a, b), pa(a, b));
		return (pa(a, b), pa(a, b));
	}
	else if (len == 3)
	{
		right_s_three(a, b, pos);
	}
}

void	sort_r_m(t_stack **a, t_stack **b, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
		rra(a);
	sort_l_l(a, b, len);
}

void	sort_r_l(t_stack **a, t_stack **b, int len)
{
	sort_l_l(a, b, len);
}

void	right_s_three(t_stack **a, t_stack **b, t_position pos)
{
	if (pos.top < pos.mid && pos.top < pos.last)
	{
		pa(a, b);
		if (pos.mid < pos.last)
			sb(b);
		return (rb(b), rb(b), pb(a, b), rrb(b), rrb(b), pa(a, b), pa(a, b),
			pa(a, b));
	}
	else if (pos.top > pos.last && pos.top > pos.mid)
	{
		if (pos.mid < pos.last)
			return (rb(b), sb(b), rrb(b), pa(a, b), pa(a, b), pa(a, b));
		return (pa(a, b), pa(a, b), pa(a, b));
	}
	else if ((pos.top > pos.mid && pos.top < pos.last) || (pos.top < pos.mid
			&& pos.top > pos.last))
	{
		if (pos.mid < pos.last)
		{
			rb(b);
			sb(b);
			rrb(b);
		}
		return (sb(b), pa(a, b), pa(a, b), pa(a, b));
	}
}
