/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_sort_few.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:57:18 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/06 23:31:38 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cmd(t_stack *a, t_stack *b, int cmd, int *flag)
{
	*flag = 0;
	if (cmd == SA)
		swap(a);
	else if (cmd == SB)
		swap(b);
	else if (cmd == SS)
		return (swap(a), swap(b));
	else if (cmd == PA && b->next != b)
		push(&b, &a);
	else if (cmd == PB && a->next != a)
		push(&a, &b);
	else if ((cmd == PA && b->next == b) || (cmd == PB && a->next == a))
		*flag = 1;
	else if (cmd == RA)
		rotate(&a);
	else if (cmd == RB)
		rotate(&b);
	else if (cmd == RR)
		return (rotate(&a), rotate(&b));
	else if (cmd == RRA)
		r_rotate(&a);
	else if (cmd == RRB)
		r_rotate(&b);
	else if (cmd == RRR)
		return (r_rotate(&a), r_rotate(&b));
}

void	remove_cmd(t_stack *a, t_stack *b, int cmd, int flag)
{
	if (cmd == SA)
		swap(a);
	else if (cmd == SB)
		swap(b);
	else if (cmd == SS)
		return (swap(a), swap(b));
	else if (cmd == PA && flag == 0)
		push(&a, &b);
	else if (cmd == PB && flag == 0)
		push(&b, &a);
	else if (cmd == RA)
		r_rotate(&a);
	else if (cmd == RB)
		r_rotate(&b);
	else if (cmd == RR)
		return (r_rotate(&a), r_rotate(&b));
	else if (cmd == RRA)
		rotate(&a);
	else if (cmd == RRB)
		rotate(&b);
	else if (cmd == RRR)
		return (rotate(&a), rotate(&b));
}

void	print_cmd(t_ans *ans, t_stack **a, t_stack **b)
{
	int	i;
	int	len;

	i = 0;
	len = ans->save[12];
	while (i < len)
	{
		choose_cmd(i, ans, a, b);
		i++;
	}
}

void	choose_cmd(int i, t_ans *ans, t_stack **a, t_stack **b)
{
	if (ans->save[i] == SA)
		sa(a);
	else if (ans->save[i] == SB)
		sb(b);
	else if (ans->save[i] == SS)
		return (sa(a), sb(b));
	else if (ans->save[i] == PA)
		pa(a, b);
	else if (ans->save[i] == PB)
		pb(a, b);
	else if (ans->save[i] == RA)
		ra(a);
	else if (ans->save[i] == RB)
		rb(b);
	else if (ans->save[i] == RR)
		return (ra(a), rb(b));
	else if (ans->save[i] == RRA)
		rra(a);
	else if (ans->save[i] == RRB)
		rrb(b);
	else if (ans->save[i] == RRR)
		return (rra(a), rrb(b));
}
