/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:12:26 by jveras            #+#    #+#             */
/*   Updated: 2024/07/12 19:24:12 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/functions.h"

static bool	check_satisfy(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_mtx);
	if (philo->meals == philo->data->num_of_meals)
	{
		pthread_mutex_unlock(&philo->data->data_mtx);
		return (false);
	}
	pthread_mutex_unlock(&philo->data->data_mtx);
	return (true);
}

bool	check_all_satisfy(t_philo *philo)
{
	unsigned int	count;
	unsigned long	i;

	count = 0;
	i = 0;
	while (i < philo->data->num_of_philos)
	{
		if (check_satisfy(&philo[i]) == 0)
			count++;
		i++;
	}
	if (count == philo->data->num_of_philos)
		return (true);
	return (false);
}

bool	check_all_alive(t_data *data)
{
	pthread_mutex_lock(&data->data_mtx);
	if (!data->philos_alive)
	{
		pthread_mutex_unlock(&data->data_mtx);
		return (false);
	}
	pthread_mutex_unlock(&data->data_mtx);
	return (true);
}
