/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:41:36 by lpicciri          #+#    #+#             */
/*   Updated: 2026/07/26 21:59:30 by luca             ###   ########.fr       */
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
	static int				bit;
	static unsigned char	c;

	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void) argv;
	if (argc != 1)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	pid = getpid();
	print_pid(pid);
	sa.sa_handler = ft_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
