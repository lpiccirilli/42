/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:14 by lpicciri          #+#    #+#             */
/*   Updated: 2023/03/09 15:34:01 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signals(pid_t pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	pid = ft_atoi(av[1]);
	i = 0;
	if (ac != 3)
	{
		printf("devono essere tre coglione");
		return (1);
	}
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			ft_send_signals(pid, av[2][i]);
			i++;
		}
	}
	printf("%c", '\n');
}
