/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:03:34 by lpicciri          #+#    #+#             */
/*   Updated: 2026/07/25 15:24:15 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			++count;
			while (s[i] && s[i] != c)
				++i;
		}
		else
			i++;
	}
	return (count + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	matrix = malloc(sizeof(char *) * (ft_counter(s, c)));
	if (!matrix)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c && ++j)
				++s;
			matrix[i++] = ft_substr(s - j, 0, j);
		}
		else
			++s;
	}
	matrix[i] = 0;
	return (matrix);
}
