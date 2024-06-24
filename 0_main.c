/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:07:16 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/24 21:32:44 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*arr;
	int		arrlen;
	t_stack	*stack_a;
	t_stack	*stack_b;

	arr = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		arr = format_one_arg(argv[1], &arrlen);
		if (!arr)
			return (0);
	}
	else
		arr = format_args(argv + 1, &arrlen);
	if (!arr)
		return (0);
	stack_a = arr2circular(arr, arrlen);
	free(arr);
	stack_b = ft_lstnew(-1);
	push_swap(stack_a, stack_b);
	ft_lstclear(&stack_a, &stack_b);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }