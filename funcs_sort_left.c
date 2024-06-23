/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_sort_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:35:52 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 12:58:30 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_l_s(t_stack **a, t_stack **b, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
		rrb(b);
	sort_r_s(a, b, len);
}

void	sort_l_m(t_stack **a, t_stack **b, int len)
{
	sort_r_s(a, b, len);
}

void	sort_l_l(t_stack **a, t_stack **b, int len)
{
	t_position	pos;

	pos.top = (*a)->next->num;
	pos.mid = (*a)->next->next->num;
	pos.last = (*a)->next->next->next->num;
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if (pos.top > pos.mid)
			return (sa(a));
	}
	else if (len == 3)
		sort_l_l_three(a, b, pos);
}

void	sort_l_l_three(t_stack **a, t_stack **b, t_position pos)
{
	if (pos.top < pos.mid && pos.top < pos.last)
	{
		if (pos.mid > pos.last)
			return (ra(a), sa(a), rra(a));
		return ;
	}
	else if (pos.top > pos.last && pos.top > pos.mid)
	{
		pb(a, b);
		if (pos.mid > pos.last)
			sa(a);
		return (ra(a), ra(a), pa(a, b), rra(a), rra(a));
	}
	else if ((pos.top > pos.mid && pos.top < pos.last)
		|| (pos.top < pos.mid && pos.top > pos.last))
	{
		if (pos.mid > pos.last)
		{
			ra(a);
			sa(a);
			rra(a);
		}
		return (sa(a));
	}
}
