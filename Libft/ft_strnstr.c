/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:07:14 by lpicciri          #+#    #+#             */
/*   Updated: 2023/01/26 18:07:37 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!little)
		return ((char *)big);
	while (i < n)
	{
		if (big[i] != little[y])
			i++;
		while ((big[i + y] == little[y]) && n > (i + y))
		{
			y++;
			if (little[y] == '\0')
				return ((char *)big + i);
			if (big[i + y] != little[y])
			{
				i++;
				y = 0;
			}
		}
	}
	return (NULL);
}
