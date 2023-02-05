/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:05:03 by lpicciri          #+#    #+#             */
/*   Updated: 2023/01/27 19:13:45 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	y;
	char	*allocated;

	allocated = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!allocated || (!s1 || !s2))
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i] != '\0')
	{
		allocated[i] = s1[i];
		i++;
	}
	while (s2[y] != '\0')
	{
		allocated[i] = s2[y];
		i++;
		y++;
	}
	allocated[i] = '\0';
	return (allocated);
}
