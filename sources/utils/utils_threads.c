/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:41:39 by jveras            #+#    #+#             */
/*   Updated: 2024/07/08 11:01:13 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/functions.h"

void	create_threads(t_data *data, void *(*routine)(void *))
{
	unsigned long	i;
	
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_create(&data->philos[i].philo, NULL, routine, &data->philos[i]);
		i++;
	}
}

void	join_threads(t_data *data)
{
	unsigned long	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_join(data->philos[i].philo, NULL);
		i++;
	}
}
