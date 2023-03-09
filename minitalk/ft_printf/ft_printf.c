/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:05 by lpicciri          #+#    #+#             */
/*   Updated: 2023/02/20 20:20:06 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int nbr)
{
	long long int	n;
	int				len;

	n = nbr;
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += ft_putchar('-');
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
	}
	len += ft_putchar((n % 10) + 48);
	return (len);
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

int	ft_control(va_list *args, char format)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter += ft_putchar(va_arg(*args, long long int));
	else if (format == 'u')
		counter += ft_printunsigned(va_arg(*args, int));
	else if (format == 'd' || format == 'i')
		counter += ft_printnbr(va_arg(*args, int));
	else if (format == 's')
		counter += ft_putstr(va_arg(*args, char *));
	else if (format == 'x' || format == 'X')
		counter += ft_printhex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		counter += ft_putchar('%');
	else if (format == 'p')
		counter += ft_print_ptr(va_arg(*args, unsigned long long));
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed;

	printed = 0;
	i = 0;
	va_start (args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			printed += ft_control(&args, str[i + 1]);
			i++;
		}
		else if (str[i] != '%')
			printed += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (printed);
}
