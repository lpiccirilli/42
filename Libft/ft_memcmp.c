/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:02:59 by lpicciri          #+#    #+#             */
/*   Updated: 2023/01/26 18:03:02 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*temp_str1;
	char	*temp_str2;

	temp_str1 = (char *)str1;
	temp_str2 = (char *)str2;
	i = 0;
	while (i < n)
	{
		if (temp_str1[i] == temp_str2[i])
			i++;
		else
			return (temp_str1[i] - temp_str2[i]);
	}
	return (0);
}
