/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:05 by lpicciri          #+#    #+#             */
/*   Updated: 2023/02/03 09:01:00 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char *str, va_list args, size_t i)
{
	int	counter;

	counter = 0;
	if (str[i] == 'c')
		counter += ft_putchar(va_arg(args, int));
	if (str[i] == 'd' || str[i] == 'i')
		counter += ft_putnbr(va_arg(args, long long int));
	else if (str[i] == 'u')
		counter += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (str[i] == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (str[i] == 'x')
		counter
			+= ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str[i] == 'X')
		counter
			+= ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str[i] == '%')
		counter += ft_putchar('%');
	else if (str[i] == 'p')
	{
		counter += 2;
		counter += ft_convertion_ptr(va_arg(args, void *));
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int		printed;

	i = 0;
	printed = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != 37)
		{
			printed += ft_putchar(str[i]);
			i++;
		}
		else if (str[i] == 37)
		{
			if (str[i + 1] == '#' || str[i + 1] == '-' || str[i + 1] == '0'
				|| str[i + 1] == '+' || str[i + 1] == ' ' || str[i + 1] == '.')
				printed += ft_bonus((char *)str, ++i);
			printed += ft_control((char *)str, args, i + 1);
			i += 2;
		}
	}
	va_end(args);
	return (printed);
}
