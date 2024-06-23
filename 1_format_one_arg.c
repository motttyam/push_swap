/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_format_one_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:37:43 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 21:11:24 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*format_one_arg(char *str, int *arrlen)
{
	char	**box;
	int		*arr;

	box = ft_split(str, ' ');
	if (!box)
		return (NULL);
	*arrlen = ft_boxlen(box);
	if (*arrlen < 2)
	{
		isnum(*box);
		boxfree(box);
		return (NULL);
	}
	arr = box_to_arr(box, arrlen);
	boxfree(box);
	return (arr);
}

void	boxfree(char **box)
{
	char	**temp;

	if (!box)
		exit(1);
	temp = box;
	while (*box)
	{
		free(*box);
		box++;
	}
	free(temp);
}

int	*box_to_arr(char **box, int *arrlen)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * (*arrlen));
	if (!arr)
	{
		write(1, "error: arr is NULL\n", 20);
		boxfree(box);
		return (NULL);
	}
	i = 0;
	while (box[i])
	{
		if (isnum(box[i]) == 1)
		{
			arr[i] = ft_atoi(box[i]);
			i++;
		}
		else
			return (free(arr), NULL);
	}
	return (arr);
}
