/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:54:29 by luca              #+#    #+#             */
/*   Updated: 2023/01/26 18:20:52 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	const char	*temp_src;
	size_t		i;
	size_t		len;

	temp_src = (const char *)src;
	temp_dest = (char *)dest;
	i = 0;
	len = ft_strlen(src);
	if ((!src && !dest) || n == 0)
		return ((void *)src);
	if (n > len + 1)
		return (0);
	while (i < len)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	temp_dest[i] = '\0';
	return ((void *) temp_dest);
}
