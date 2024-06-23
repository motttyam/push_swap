/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_lens_cpys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:49:31 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/06 23:53:45 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_boxlen(char **box)
{
	int	i;

	i = 0;
	if (!box)
	{
		write(1, "error: box is NULL\n", 19);
		exit(1);
	}
	while (box[i])
		i++;
	return (i);
}

int	*arrcpy(int *arr, int arrlen)
{
	int	i;
	int	*cp_arr;

	if (!arr)
	{
		write(1, "unexpected error in arrcpy\n", 28);
		exit(1);
	}
	cp_arr = (int *)malloc(sizeof(int) * (arrlen));
	if (!cp_arr)
	{
		write(1, "malloc error in arrcpy\n", 24);
		exit(1);
	}
	i = 0;
	while (i < arrlen)
	{
		cp_arr[i] = arr[i];
		i++;
	}
	return (cp_arr);
}
