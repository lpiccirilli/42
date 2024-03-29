/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:35:15 by lpicciri          #+#    #+#             */
/*   Updated: 2023/06/18 17:07:54 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = (uint64_t)ft_atoi(argv[2]);
	data->t_eat = (uint64_t)ft_atoi(argv[3]);
	data->t_sleep = (uint64_t)ft_atoi(argv[4]);
	data->finished = 0;
	data->enough = 0;
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	else
		data->n_eat = -1;
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
	return (0);
}

int	alloc(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (-1);
	data->thread_id = malloc(sizeof(pthread_t) * data->n_philo);
	if (!data->thread_id)
		return (-1);
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		return (-1);
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	data->philo[0].l_fork = &data->forks[0];
	data->philo[0].r_fork = &data->forks[data->n_philo - 1];
	i = 0;
	while (++i < data->n_philo)
	{
		data->philo[i].l_fork = &data->forks[i];
		data->philo[i].r_fork = &data->forks[i - 1];
	}
	return (0);
}

int	init_philo_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].eaten = 0;
		data->philo[i].t_die = data->t_die;
		data->philo[i].last_eat = get_time();
		data->philo[i].eating = 0;
		if(pthread_mutex_init(&data->philo[i].eat_lock, NULL))
			return (-1);
		i++;
	}
	return (0);
}

int	init(t_data *data, char **argv)
{
	if (init_data(data, argv) == -1)
		return (-1);
	if (alloc (data) == -1)
		return (-1);
	if (init_philo_data (data) == -1)
		return (-1);
	if (init_forks (data) == -1)
		return (-1);
	if (data->n_philo == 1)
		return (case_one(data));
	printf("sono qui\n");
	if (init_threads(data) == -1)
		return (-1);
	free_data(data);
	return (0);
}
