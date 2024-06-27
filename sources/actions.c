/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:25:34 by jveras            #+#    #+#             */
/*   Updated: 2024/06/27 15:09:57 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/functions.h"
#include "../includes/color_codes.h"

void	philo_to_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_mtx);

	pthread_mutex_lock(&philo->left_fork->fork);
	printf("%ld %d has taken a fork\n", get_time(), philo->id);
	pthread_mutex_lock(&philo->right_fork->fork);
	printf("%ld %d has taken a fork\n", get_time(), philo->id);

	printf("%ld %d is eating\n", get_time(), philo->id);
	usleep(philo->data->time_to_eat);

	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);

	pthread_mutex_unlock(&philo->data->data_mtx);
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
