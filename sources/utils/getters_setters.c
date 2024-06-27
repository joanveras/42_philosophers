/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:01:57 by jveras            #+#    #+#             */
/*   Updated: 2024/06/27 14:31:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"

void	set_bool(pthread_mutex_t *mtx, bool *dest, bool value)
{
	pthread_mutex_lock(mtx);
	*dest = value;
	pthread_mutex_unlock(mtx);
}

bool	get_bool(pthread_mutex_t *mtx, bool *value)
{
	bool	ret;

	pthread_mutex_lock(mtx);
	ret = *value;
	pthread_mutex_unlock(mtx);
	return (ret);
}
