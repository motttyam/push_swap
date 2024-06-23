/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_few.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:45:41 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/06 23:55:09 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_few(t_stack *stack_a, t_stack *stack_b)
{
	t_ans	*ans;
	int		i;

	ans = (t_ans *)malloc(sizeof(t_ans));
	if (!ans)
	{
		write(1, "error\n", 6);
		return ;
	}
	ans->save[12] = 9;
	i = 0;
	while (i < 10)
	{
		ans->save[i] = -1;
		i++;
	}
	search_dfs(stack_a, stack_b, ans, 1);
	print_cmd(ans, &stack_a, &stack_b);
	free(ans);
}

void	search_dfs(t_stack *stack_a, t_stack *stack_b, t_ans *ans, int move)
{
	int	cmd;
	int	flag;

	cmd = 0;
	flag = 0;
	if (move > ans->save[12] || (is_sorted(stack_a)
			&& stack_b->next == stack_b))
		return ;
	while (cmd < 11)
	{
		ans->ans[move - 1] = cmd;
		move_cmd(stack_a, stack_b, cmd, &flag);
		if (is_sorted(stack_a) && stack_b->next == stack_b)
		{
			save_ans(ans, move);
			remove_cmd(stack_a, stack_b, cmd, flag);
			return ;
		}
		search_dfs(stack_a, stack_b, ans, move + 1);
		remove_cmd(stack_a, stack_b, cmd, flag);
		cmd++;
	}
}

void	save_ans(t_ans *ans, int move)
{
	int	i;

	if (move < ans->save[12])
	{
		i = 0;
		while (i < move)
		{
			ans->save[i] = ans->ans[i];
			i++;
		}
		ans->save[12] = i;
	}
}
