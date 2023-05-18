/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:41:36 by lpicciri          #+#    #+#             */
/*   Updated: 2023/05/18 12:34:46 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

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

void	print_pid(pid_t pid)
{
	ft_putnbr(pid);
	write(1, "\n", 1);
}

void	ft_signal(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void) argv;
	if (argc != 1)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	pid = getpid();
	print_pid(pid);
	while (argc == 1)
	{
		signal (SIGUSR1, ft_signal);
		signal (SIGUSR2, ft_signal);
		pause ();
	}
	return (0);
}
