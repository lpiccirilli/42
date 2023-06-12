/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:06:12 by lpicciri          #+#    #+#             */
/*   Updated: 2023/06/12 19:58:51 by lpicciri         ###   ########.fr       */
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
	messages("is eating", philo);
	ft_usleep(philo->data->t_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	messages("is sleeping", philo);
	ft_usleep(philo->data->t_sleep);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *) arg;
	data = philo->data;
	philo->eaten = 0;
	pthread_create(&philo->monitor_id, NULL, &monitor, data);
	while(philo->dead == false && philo->eaten != philo->data->n_eat)
	{
		eat(philo);
	}
	pthread_join(philo->monitor_id, NULL);
	return (NULL);
}
void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *) arg;
	i = -1;
	while (1)
	{
		while (++i < data->n_philo)
		{
			pthread_mutex_lock(&data->lock);
			if (data->philo[i].eaten >= 1 && (get_time() - data->philo[i].last_eat) > data->t_die)
				printf("dead");
			pthread_mutex_unlock(&data->lock);
		}
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
