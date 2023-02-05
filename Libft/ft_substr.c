/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:08:10 by lpicciri          #+#    #+#             */
/*   Updated: 2023/01/27 19:20:09 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*allocated;
	size_t	i;

	i = 0;
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	allocated = (char *)malloc(len + 1);
	if (!allocated || !str)
		return (NULL);
	while (i < len)
	{
		allocated[i] = str[start];
		start++;
		i++;
	}
	allocated[len] = '\0';
	return (allocated);
}
