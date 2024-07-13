/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:08:28 by jveras            #+#    #+#             */
/*   Updated: 2024/07/12 19:30:36 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/functions.h"

void	*dinner_simulation(void *sopher)
{
	t_philo	*philo;

	philo = (t_philo *)sopher;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat);
	while (check_all_alive(philo->data)
		&& (philo->data->num_of_meals == 0
			|| philo->data->num_of_meals > philo->meals))
	{
		if (philo_to_eat(philo))
			return (NULL);
		philo_to_sleep(philo);
		philo_to_think(philo);
	}
	return ((void *)philo);
}

void	dinner_start(t_data *data)
{
	data->simulation_start_time = get_time();
	create_threads(data, dinner_simulation);
	monitor(data->philos);
	join_threads(data);
}
