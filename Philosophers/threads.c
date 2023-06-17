/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:06:12 by lpicciri          #+#    #+#             */
/*   Updated: 2023/06/17 12:48:29 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf("%llu %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_lock(philo->r_fork);
	printf("%llu %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_lock(&philo->data->lock);
	philo->eaten++;
	printf("%llu %d is eating\n", get_time() - philo->data->start_time, philo->id);
	ft_usleep(philo->data->t_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->data->lock);
	printf("%llu %d is sleeping\n", get_time() - philo->data->start_time, philo->id);
	ft_usleep(philo->data->t_sleep);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (philo->dead == false)
	{
			pthread_mutex_lock(&philo->data->lock);
			if (get_time() - philo->last_eat > philo->t_die)
			{
				philo->dead = true;
				printf("%llu %d died\n", get_time() - philo->data->start_time, philo->id);
			}
			pthread_mutex_unlock(&philo->data->lock);
	}
	return(NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	philo->eaten = 0;
	pthread_create(&philo->monitor_id, NULL, &monitor, philo);
	while(philo->dead == false && philo->eaten != philo->data->n_eat)
	{
		eat(philo);
	}
	return (NULL);
}

int	init_threads(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_time();
	while (++i < data->n_philo)
		pthread_create(&data->thread_id[i], NULL, &routine, &data->philo[i]);
	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->thread_id[i], NULL);
	return (0);
}
