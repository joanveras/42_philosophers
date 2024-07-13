/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:14:16 by jveras            #+#    #+#             */
/*   Updated: 2024/07/13 13:26:54 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "libft.h"
# include "structs.h"

# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <sys/time.h>

bool		monitor(t_philo *philo);
bool		philo_to_eat(t_philo *philo);
bool		check_all_alive(t_data *data);
bool		handle_bad_cases(t_data *data);
bool		check_all_satisfy(t_philo *philo);
bool		arguments_err(int argc, char **argv);

void		free_data(t_data *data);
void		init_forks(t_data **data);
void		print_eat(t_philo *philo);
void		print_die(t_philo *philo);
void		dinner_start(t_data *data);
void		init_philos(t_data **data);
void		join_threads(t_data *data);
void		print_fork(t_philo *philo);
void		print_sleep(t_philo *philo);
void		print_think(t_philo *philo);
void		philo_to_sleep(t_philo *philo);
void		philo_to_think(t_philo *philo);
void		init_data(t_data **data, char **argv);
void		create_threads(t_data *data, void *(*routine)(void *));
void		define_forks(t_fork **first_fork, t_fork **second_fork, \
			t_philo *philo);

long		ft_atol(const char *nptr);

uint64_t	get_time(void);

#endif