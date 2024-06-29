/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:08:28 by jveras            #+#    #+#             */
/*   Updated: 2024/06/29 09:48:42 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/functions.h"

void	*dinner_simulation(void *sopher)
{
	t_philo	*philo;

	philo = (t_philo *)sopher;
	while (true)
	{
		philo_to_eat(philo);
		philo_to_sleep(philo);
		/* philo_to_think(philo); */
	}
}

void	dinner_start(t_data *data)
{
	if (!data->num_of_meals)
		return ;
	create_threads(data, dinner_simulation);
	join_threads(data);
}
