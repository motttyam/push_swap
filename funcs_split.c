/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:17:05 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/05/15 22:21:57 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

int	ft_split2(char **dest, int j, const char *s, int len)
{
	int	k;

	dest[j] = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest[j])
	{
		while (j > 0)
		{
			free(dest[--j]);
		}
		free(dest);
		dest = NULL;
		return (1);
	}
	k = 0;
	while (k < len)
	{
		dest[j][k] = s[k];
		k++;
	}
	dest[j][k] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		old_i;
	int		j;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		old_i = i;
		while (s[i] && s[i] != c)
			i++;
		if (old_i < i)
			if (ft_split2(dest, j++, s + old_i, i - old_i) == 1 && !dest)
				return (NULL);
	}
	dest[j] = NULL;
	return (dest);
}
