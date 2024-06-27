/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:21:15 by jveras            #+#    #+#             */
/*   Updated: 2024/06/27 14:24:41 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include <stdbool.h>

typedef struct  s_data t_data;

typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			meals;
	pthread_t		philo;
	t_fork			*right_fork;
	t_fork			*left_fork;
	t_data			*data;
}	t_philo;

typedef struct	s_data
{
	t_fork			*forks;
	t_philo			*philos;
	unsigned long	num_of_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	num_of_meals;
	bool			all_threads_ready;
	pthread_mutex_t	data_mtx;
}	t_data;

#endif