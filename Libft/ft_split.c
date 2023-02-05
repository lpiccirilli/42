/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:03:34 by lpicciri          #+#    #+#             */
/*   Updated: 2023/01/27 18:59:58 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *string, char separator)
{
	int	count;
	int	i;
	int	len;

	count = 0;
	i = 0;
	len = ft_strlen(string);
	if (string[0] != separator)
		count++;
	while (i < len)
	{
		while (string[i] == separator && i < len)
			i++;
		if (string[i] != separator && string[i - 1] == separator && i < len)
		{
			count++;
			i++;
		}
		i++;
	}
	return (count + 1);
}

static char	*ft_string(char const *s, char c)
{
	size_t	i;
	char	*string;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	i = 0;
	if (s[i] == '\0')
		return (NULL);
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
		return (0);
	while (i < len)
	{
		string[i] = s[i];
			i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	matrix = malloc((sizeof(char *)) * (ft_count(s, c)));
	if (!matrix)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			matrix[y] = ft_string(s + i, c);
			i++;
			y++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		i++;
	}
	matrix[y] = NULL;
	return (matrix);
}
