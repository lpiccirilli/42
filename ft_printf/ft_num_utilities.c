/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:43:19 by lpicciri          #+#    #+#             */
/*   Updated: 2026/07/25 21:55:32 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_printnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len += ft_putnbr(nbr);
	return (len);
}

int	ft_printunsigned(unsigned int unsnbr)
{
	int	len;

	len = 0;
	if (unsnbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len += ft_putnbr(unsnbr);
	return (len);
}

int	ft_putnbr(long long nb)
{
	long long	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
	return (ft_countnbr(nb, "0123456789"));
}
