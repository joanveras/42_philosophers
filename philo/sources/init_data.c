/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:33:28 by jveras            #+#    #+#             */
/*   Updated: 2024/07/13 13:23:35 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/functions.h"

void	init_data(t_data **data, char **argv)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
	{
		ft_putstr_fd("malloc error: (t_data)data\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	(*data)->num_of_philos = ft_atol(argv[1]);
	(*data)->time_to_die = ft_atol(argv[2]);
	(*data)->time_to_eat = ft_atol(argv[3]) * 1000;
	(*data)->time_to_sleep = ft_atol(argv[4]) * 1000;
	(*data)->simulation_start_time = 0;
	(*data)->philos_alive = true;
	pthread_mutex_init(&(*data)->data_mtx, NULL);
	if (!argv[5])
	{
		(*data)->num_of_meals = 0;
		return ;
	}
	(*data)->num_of_meals = ft_atol(argv[5]);
}

void	init_forks(t_data **data)
{
	unsigned long	i;
	t_fork			*current_fork;

	(*data)->forks = malloc(sizeof(t_fork) * (*data)->num_of_philos);
	if (!(*data)->forks)
	{
		ft_putstr_fd("malloc error: (t_forks *)forks\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < (*data)->num_of_philos)
	{
		current_fork = &(*data)->forks[i];
		(*data)->forks[i].fork_id = i + 1;
		pthread_mutex_init(&current_fork->fork, NULL);
		i++;
	}
}

void	init_philos(t_data **data)
{
	unsigned long	i;
	t_philo			*current_philo;

	(*data)->philos = malloc(sizeof(t_philo) * (*data)->num_of_philos);
	if (!(*data)->philos)
	{
		ft_putstr_fd("malloc error: (t_philo *)philos\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < (*data)->num_of_philos)
	{
		current_philo = &(*data)->philos[i];
		current_philo->id = i + 1;
		current_philo->meals = 0;
		current_philo->last_meal = 0;
		current_philo->left_fork = &(*data)->forks[i];
		current_philo->right_fork = &(*data)->forks[((i + 1) % \
			(*data)->num_of_philos)];
		current_philo->data = *data;
		i++;
	}
}
