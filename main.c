/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:13:51 by jveras            #+#    #+#             */
/*   Updated: 2024/06/27 13:51:28 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/structs.h"
#include "includes/functions.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	
	if (arguments_err(argc, argv))
		return (1);
	init_data(&data, argv);
	if (handle_bad_cases(data))
		return (1);
	init_forks(&data);
	init_philos(&data);
	dinner_start(data);
	

	return (0);
}
