/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:25:34 by jveras            #+#    #+#             */
/*   Updated: 2024/07/08 14:55:19 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/functions.h"

void	philo_to_eat(t_philo *philo)
{
	t_fork	*first_fork;
	t_fork	*second_fork;
	
	define_forks(&first_fork, &second_fork, philo);
	
	pthread_mutex_lock(&first_fork->fork);
	print_fork(philo);
	pthread_mutex_lock(&second_fork->fork);
	print_fork(philo);

	print_eat(philo);
	usleep(philo->data->time_to_eat);

	pthread_mutex_unlock(&first_fork->fork);
	pthread_mutex_unlock(&second_fork->fork);
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
