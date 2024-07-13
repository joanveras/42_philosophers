/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:24:05 by jveras            #+#    #+#             */
/*   Updated: 2024/07/13 13:24:54 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/functions.h"
#include "../../includes/color_codes.h"

void	print_fork(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->data_mtx);
	if (!philo->data->philos_alive)
	{
		pthread_mutex_unlock(&philo->data->data_mtx);
		return ;
	}
	pthread_mutex_unlock(&philo->data->data_mtx);
	time = (get_time() - philo->data->simulation_start_time) % 10000;
	pthread_mutex_lock(&philo->data->data_mtx);
	printf("%s%04lu%s %d has taken a fork\n", \
		URED, time, COLOR_RESET, philo->id);
	pthread_mutex_unlock(&philo->data->data_mtx);
}

void	print_eat(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->data_mtx);
	if (!philo->data->philos_alive)
	{
		pthread_mutex_unlock(&philo->data->data_mtx);
		return ;
	}
	pthread_mutex_unlock(&philo->data->data_mtx);
	time = (get_time() - philo->data->simulation_start_time);
	pthread_mutex_lock(&philo->data->data_mtx);
	philo->last_meal = time;
	printf("%s%04lu%s %d is %seating%s\n", \
		URED, time % 10000, COLOR_RESET, philo->id, HMAG, COLOR_RESET);
	pthread_mutex_unlock(&philo->data->data_mtx);
}

void	print_sleep(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->data_mtx);
	if (!philo->data->philos_alive)
	{
		pthread_mutex_unlock(&philo->data->data_mtx);
		return ;
	}
	pthread_mutex_unlock(&philo->data->data_mtx);
	time = (get_time() - philo->data->simulation_start_time) % 10000;
	pthread_mutex_lock(&philo->data->data_mtx);
	printf("%s%04lu%s %d is %ssleeping%s\n", \
		URED, time, COLOR_RESET, philo->id, HBLU, COLOR_RESET);
	pthread_mutex_unlock(&philo->data->data_mtx);
}

void	print_think(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->data_mtx);
	if (!philo->data->philos_alive)
	{
		pthread_mutex_unlock(&philo->data->data_mtx);
		return ;
	}
	pthread_mutex_unlock(&philo->data->data_mtx);
	time = (get_time() - philo->data->simulation_start_time) % 10000;
	pthread_mutex_lock(&philo->data->data_mtx);
	printf("%s%04lu%s %d is %sthinking%s\n", \
		URED, time, COLOR_RESET, philo->id, HCYN, COLOR_RESET);
	pthread_mutex_unlock(&philo->data->data_mtx);
}

void	print_die(t_philo *philo)
{
	uint64_t	time;

	time = (get_time() - philo->data->simulation_start_time) % 10000;
	pthread_mutex_lock(&philo->data->data_mtx);
	printf("%s%04lu%s %d %sdied%s\n", \
		URED, time, COLOR_RESET, philo->id, HBLK, COLOR_RESET);
	pthread_mutex_unlock(&philo->data->data_mtx);
}
