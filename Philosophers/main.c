/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:50:34 by lpicciri          #+#    #+#             */
/*   Updated: 2023/06/07 20:09:17 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	messages("has taken a fork", philo);
	pthread_mutex_lock(philo->r_fork);
	messages("has taken a fork", philo);
	pthread_mutex_lock(&philo->lock);
	philo->eaten++;
	philo->eating = 1;
	messages("is eating", philo);
	ft_usleep(philo->data->t_eat);
	philo->last_eat = get_time();
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	messages("is sleeping", philo);
	ft_usleep(philo->data->t_sleep);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) == -1)
		return (printf("Error: wrong arguments\n"));
	if (init(&data, argv) == -1)
		return (printf("Error: init_data\n"));
	if (init_threads(&data) == -1)
		return (printf("Error: init_threads\n"));
	return (0);
}
