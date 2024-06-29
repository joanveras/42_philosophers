/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessign_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:36:08 by jveras            #+#    #+#             */
/*   Updated: 2024/06/29 09:36:16 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"

void	dessign_forks(t_philo *philo, t_fork *fork, int philo_pos)
{
	int	philo_num;

	philo_num = philo->data->num_of_philos;
	philo->right_fork = fork + ((philo_pos + 1) % philo_num);
	philo->left_fork = fork + philo_pos;
	if (philo->id % 2 == 0)
	{
		philo->right_fork = fork + philo_num;
		philo->left_fork = fork + ((philo_pos + 1) % philo_num);
	}
}
