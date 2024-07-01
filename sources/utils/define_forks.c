/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:36:35 by jveras            #+#    #+#             */
/*   Updated: 2024/06/29 09:36:58 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"

void	define_forks(t_fork **first_fork, t_fork **second_fork, t_philo *philo)
{
	if ((unsigned long)philo->id == philo->data->num_of_philos - 1)
	{
		*first_fork = &philo->data->forks[(philo->id + 1) % \
			philo->data->num_of_philos];
		*second_fork = &philo->data->forks[philo->id];
	}
	else
	{
		*first_fork = &philo->data->forks[philo->id];
		*second_fork = &philo->data->forks[(philo->id + 1) % \
			philo->data->num_of_philos];
	}
}

/*

	using this function,
	the last philosopher clearly dies int the start

void	define_forks(t_fork **first_fork, t_fork **second_fork, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		*first_fork = &philo->data->forks[philo->id];
		*second_fork = &philo->data->forks[(philo->id + 1) %
			philo->data->num_of_philos];
	}
	else
	{
		*first_fork = &philo->data->forks[(philo->id + 1) %
			philo->data->num_of_philos];
		*second_fork = &philo->data->forks[philo->id];
	}
}
*/