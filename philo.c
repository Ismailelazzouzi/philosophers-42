/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <isel-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 06:28:49 by isel-azz          #+#    #+#             */
/*   Updated: 2024/10/18 07:18:19 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_store			table;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	table.philos = philos;
	table.forks = forks;
	if (argc == 5 || argc == 6)
	{
		check_args(argv);
		parse(&table, argv);
		innit_all(&table, forks);
		create_threads(&table);
		destroy_all(NULL, &table);
	}
	else
		return (write(2, "Wrong argument count\n", 22), 1);
	return (0);
}
