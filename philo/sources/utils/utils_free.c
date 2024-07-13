/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:05:57 by jveras            #+#    #+#             */
/*   Updated: 2024/07/13 13:09:11 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/functions.h"

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->philos)
		{
			free(data->philos);
		}
		if (data->forks)
			free(data->forks);
		free(data);
	}
}
