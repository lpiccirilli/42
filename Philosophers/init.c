/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:35:15 by lpicciri          #+#    #+#             */
/*   Updated: 2023/06/07 19:59:49 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = (uint64_t)ft_atoi(argv[2]);
	data->t_eat = (uint64_t)ft_atoi(argv[3]);
	data->t_sleep = (uint64_t)ft_atoi(argv[4]);
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	else
		data->n_eat = -1;
	data->finish = false;
	pthread_mutex_init(&data->lock, NULL);
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
		printf("%d\n", data->philo[i].data->n_philo);
		data->philo[i].id = i + 1;
		data->philo[i].eaten = 0;
		data->philo[i].eating = 0;
		data->philo[i].t_die = data->t_die;
		pthread_mutex_init(&data->philo[i].lock, NULL);
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
	init_philo_data (data);
	if (init_forks (data) == -1)
		return (-1);
	return (0);
}
