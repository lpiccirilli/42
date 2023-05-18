/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:14 by lpicciri          #+#    #+#             */
/*   Updated: 2023/05/18 12:55:30 by lpicciri         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == ' '
		||str[i] == '\r' || str[i] == '\v')
	i++;
	if (str[i] == '-')
	sign = -1;
	if (str[i] == '-' || str[i] == '+')
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		write(1, "./client (pid) (string to be send)\n", 35);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			ft_send_signals(pid, av[2][i]);
			i++;
		}
		ft_send_signals(pid, '\n');
	}
	return (0);
}
