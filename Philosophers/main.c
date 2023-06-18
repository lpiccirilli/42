/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:50:34 by lpicciri          #+#    #+#             */
/*   Updated: 2023/06/18 16:20:43 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].eat_lock);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	if (data->thread_id)
		free(data->thread_id);
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) == -1)
		return (printf("Error: wrong arguments\n"));
	if (init(&data, argv) == -1)
		return (printf("Error: init_data\n"));
	return (0);
}
