/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:02:14 by lpicciri          #+#    #+#             */
/*   Updated: 2023/01/26 18:02:15 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t dim)
{
	void	*allocated;

	allocated = malloc(num * dim);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, (num * dim));
	return (allocated);
}
