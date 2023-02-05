/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_funcion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:43:19 by lpicciri          #+#    #+#             */
/*   Updated: 2023/02/03 08:59:22 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_convertion_ptr(void *p)
{
	uintptr_t	address;

	write(1, "0x", 2);
	if (!p)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		address = (uintptr_t)p;
		return (ft_putnbr_base ((long long)address, "0123456789abcdef"));
	}
	return (0);
}

int	ft_countnbr(long long nb, char *base)
{
	int	counter;
	int	len;

	len = ft_strlen(base);
	counter = 1;
	if (nb < 0)
	{
		counter = 2;
		nb *= -1;
	}
	while (nb > len - 1)
	{
		nb /= len;
		counter++;
	}
	return (counter);
}
