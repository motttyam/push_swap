/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_format_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:09:56 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 18:32:56 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack **a, t_stack **b);

int	*format_args(char **box, int *arrlen)
{
	int	i;
	int	*arr;

	if (!box)
		return (NULL);
	i = 0;
	*arrlen = ft_boxlen(box);
	arr = (int *)malloc(sizeof(int) * (*arrlen));
	if (!arr)
	{
		write(1, "malloc() was failed in format_args\n", 35);
		return (NULL);
	}
	while (box[i])
	{
		if (isnum(box[i]) != 1)
			return (NULL);
		arr[i] = ft_atoi(box[i]);
		i++;
	}
	return (arr);
}
