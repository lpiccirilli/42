/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:43:19 by lpicciri          #+#    #+#             */
/*   Updated: 2026/07/25 21:56:01 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(unsigned long long p)
{
	if (p >= 16)
	{
		ft_put_ptr(p / 16);
		ft_put_ptr(p % 16);
	}
	else
	{
		if (p > 9)
			ft_putchar(p - 10 + 'a');
		else
			ft_putchar(p + 48);
	}
}

int	ft_ptrlen(unsigned long long p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	return (len);
}

int	ft_print_ptr(unsigned long long p)
{
	int	len;

	len = 0;
	if (p == 0)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	len += ft_putstr("0x");
	len += ft_ptrlen(p);
	ft_put_ptr(p);
	return (len);
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

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
