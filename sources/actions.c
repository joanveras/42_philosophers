/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:25:34 by jveras            #+#    #+#             */
/*   Updated: 2024/06/29 09:41:09 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/functions.h"
#include "../includes/color_codes.h"

void	philo_to_eat(t_philo *philo)
{
	t_fork	*first_fork;
	t_fork	*second_fork;

	/* pthread_mutex_lock(&philo->data->data_mtx); */

	define_forks(&first_fork, &second_fork, philo);
	pthread_mutex_lock(&first_fork->fork);
	printf("%ld %d has taken a fork\n", get_time(), philo->id);
	pthread_mutex_lock(&second_fork->fork);
	printf("%ld %d has taken a fork\n", get_time(), philo->id);

	printf("%ld %d is eating\n", get_time(), philo->id);
	usleep(philo->data->time_to_eat);

	pthread_mutex_unlock(&first_fork->fork);
	pthread_mutex_unlock(&second_fork->fork);

	/* pthread_mutex_unlock(&philo->data->data_mtx); */
}

void	philo_to_sleep(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_time(), philo->id);
	usleep(philo->data->time_to_sleep);
}

/* void	philo_to_think(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_time(), philo->id);
} */
