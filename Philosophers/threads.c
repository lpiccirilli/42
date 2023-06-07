/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:06:12 by lpicciri          #+#    #+#             */
/*   Updated: 2023/06/07 19:58:11 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *void_data)
{
	t_data		*data;
	int			i;

	data = (t_data *) void_data;
	while (data->dead == false)
	{
		i = -1;
		printf("%d\n", data->n_philo);
		while (++i < data->n_philo)
		{
			printf("%d\n", i);
			ft_usleep(1000);
		}
	}
	return(NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	philo->eaten = 0;
	while(philo->eaten != philo->data->n_eat)
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
	pthread_create(&data->monitor_id, NULL, &monitor, &data);
	while (++i < data->n_philo)
	{
		if (pthread_create(&data->thread_id[i], NULL, &routine, &data->philo[i])
			!= 0)
			return (-1);
	}
	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->thread_id[i], NULL);
	pthread_join(data->monitor_id, NULL);
	return (0);
}
