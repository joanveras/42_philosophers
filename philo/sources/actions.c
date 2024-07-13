/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:25:34 by jveras            #+#    #+#             */
/*   Updated: 2024/07/13 13:24:00 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/functions.h"

bool	philo_to_eat(t_philo *philo)
{
	t_fork	*first_fork;
	t_fork	*second_fork;

	define_forks(&first_fork, &second_fork, philo);
	usleep(100);
	pthread_mutex_lock(&first_fork->fork);
	print_fork(philo);
	if (philo->data->num_of_philos == 1)
	{
		pthread_mutex_unlock(&first_fork->fork);
		return (true);
	}
	pthread_mutex_lock(&second_fork->fork);
	print_fork(philo);
	print_eat(philo);
	pthread_mutex_lock(&philo->data->data_mtx);
	philo->meals++;
	pthread_mutex_unlock(&philo->data->data_mtx);
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&first_fork->fork);
	pthread_mutex_unlock(&second_fork->fork);
	return (false);
}

void	philo_to_sleep(t_philo *philo)
{
	usleep(philo->data->time_to_sleep);
	print_sleep(philo);
}

void	philo_to_think(t_philo *philo)
{
	print_think(philo);
}
