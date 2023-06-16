/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:06:12 by lpicciri          #+#    #+#             */
/*   Updated: 2023/06/16 18:11:57 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf("%llu %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_lock(philo->r_fork);
	printf("%llu %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_lock(&philo->lock);
	philo->eaten++;
	printf("%llu %d is eating\n", get_time() - philo->data->start_time, philo->id);
	ft_usleep(philo->data->t_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	printf("%llu %d is sleeping\n", get_time() - philo->data->start_time, philo->id);
	ft_usleep(philo->data->t_sleep);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *) arg;
	while (philo->dead == false)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() - philo->last_eat > philo->t_die)
			{
				printf("%llu\n", get_time() - philo->last_eat);
				philo->dead = true;
			}
		i++;
		pthread_mutex_unlock(&philo->lock);
	}
	return(NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	philo->eaten = 0;
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
		pthread_create(&data->monitor_id[i], NULL, &monitor, &data->philo[i]);
	i = -1;
	while (++i < data->n_philo)
		pthread_create(&data->thread_id[i], NULL, &routine, &data->philo[i]);
	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->thread_id[i], NULL);
	return (0);
}
