/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:37:49 by jveras            #+#    #+#             */
/*   Updated: 2024/07/12 19:08:04 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/functions.h"

static int	check_died(t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(&philo->data->data_mtx);
	current_time = get_time() - philo->data->simulation_start_time;
	if ((current_time - philo->last_meal) > philo->data->time_to_die)
	{
		philo->data->philos_alive = false;
		pthread_mutex_unlock(&philo->data->data_mtx);
		print_die(philo);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->data_mtx);
	return (0);
}

static bool	check_philo(t_philo *philo)
{
	unsigned long	i;

	i = 0;
	while (i < philo->data->num_of_philos)
	{
		if (check_died(&philo[i]))
			return (true);
		else if (check_all_satisfy(philo))
			break ;
		i++;
	}
	if (philo->data->num_of_meals != 0)
	{
		if (check_all_satisfy(philo))
			return (true);
	}
	return (false);
}

bool	monitor(t_philo *philo)
{
	while (true)
	{
		if (check_philo(philo))
			break ;
		usleep(1000);
	}
	return (true);
}
