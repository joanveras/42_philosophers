/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:28:06 by jveras            #+#    #+#             */
/*   Updated: 2024/06/21 09:26:50 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/functions.h"

static bool	number_of_args_err(int argc)
{
	if (argc == 5 || argc == 6)
		return (false);
	ft_putstr_fd("error: wrong number of arguments\n", STDERR_FILENO);
	return (true);
}

static bool	check_invalid_characters(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd("error: invalid input\n", STDERR_FILENO);
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool	arguments_err(int argc, char **argv)
{
	if (number_of_args_err(argc))
		return (true);
	else if (check_invalid_characters(argv))
		return (true);
	return (false);
}

bool	handle_bad_cases(t_data *data)
{	
	if (data->num_of_philos > 200)
	{
		ft_putstr_fd("error: bad number of philosophers\n", STDERR_FILENO);
		return (true);
	}
	else if (data->time_to_die < 60)
	{
		ft_putstr_fd("error: time_to_die too low\n", STDERR_FILENO);
		return (true);
	}
	return (false);
}
