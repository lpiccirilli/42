/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:05:55 by lpicciri          #+#    #+#             */
/*   Updated: 2023/01/27 18:22:00 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			lendest;
	size_t			lensrc;
	unsigned long	i;

	lensrc = ft_strlen(src);
	lendest = ft_strlen(dest);
	i = 0;
	while (i < (size - lendest - 1))
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lendest + lensrc);
}
