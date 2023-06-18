/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:06:12 by lpicciri          #+#    #+#             */
/*   Updated: 2023/06/18 16:18:45 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf("%llu %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_lock(philo->r_fork);
	printf("%llu %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_lock(&philo->eat_lock);
	philo->eating = 1;
	printf("%llu %d is eating\n", get_time() - philo->data->start_time, philo->id);
	philo->last_eat = get_time();
	philo->eaten++;
	ft_usleep(philo->data->t_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->eat_lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	printf("%llu %d is sleeping\n", get_time() - philo->data->start_time, philo->id);
	ft_usleep(philo->data->t_sleep);
}

void	*monitor(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	while (philo->data->finished == 0)
	{
		pthread_mutex_lock(&philo->eat_lock);
		if ((get_time() - philo->last_eat) >= philo->t_die
			&& philo->eating == 0)
			printf(ANSI_COLOR_RED "%llu %d has died\n" ANSI_COLOR_RESET,
				get_time() - philo->data->start_time, philo->id);
		if (philo->eaten == philo->data->n_eat)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->enough++;
			philo->eaten++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		if (philo->data->enough == philo->data->n_philo)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished = 1;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->eat_lock);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	pthread_create(&philo->monitor_id, NULL, &monitor, philo);
	while(philo->data->finished == 0)
	{
		eat(philo);
		printf("%llu %d is thinking\n", get_time() - philo->data->start_time, philo->id);
	}
	pthread_join(philo->monitor_id, NULL);
	return (NULL);
}

int	init_threads(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_time();
	while (++i < data->n_philo)
	{
		ft_usleep(1);
		if(pthread_create(&data->thread_id[i], NULL, &routine, &data->philo[i]))
			return (-1);
	}
	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->thread_id[i], NULL);
	return (0);
}
