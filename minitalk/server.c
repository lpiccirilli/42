/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:41:36 by lpicciri          #+#    #+#             */
/*   Updated: 2023/03/09 15:26:26 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
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
		printf("ERROR");
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
