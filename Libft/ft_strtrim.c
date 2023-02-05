/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:08:05 by lpicciri          #+#    #+#             */
/*   Updated: 2023/01/27 19:17:31 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*result;
	int		i;
	int		j;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && ft_strchr(set, s1[start]) != NULL)
	start++;
	while (end >= start && ft_strchr(set, s1[end]) != NULL)
		end--;
	result = (char *) malloc(end - start + 2);
	if (!result)
		return (0);
	i = start;
	j = 0;
	while (i <= end)
		result[j++] = s1[i++];
	result[j] = '\0';
	return (result);
}
