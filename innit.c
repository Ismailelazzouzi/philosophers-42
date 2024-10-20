/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <isel-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 06:28:35 by isel-azz          #+#    #+#             */
/*   Updated: 2024/10/18 07:17:33 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	innit_philos(t_store *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		table->philos[i].table = table;
		table->philos[i].philo_id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->dinner_start = get_current_time();
		table->philos[i].last_meal = get_current_time();
		table->philos[i].l_fork = &table->forks[i];
		if (i == 0)
			table->philos[i].r_fork = &table->forks[table->philo_nbr - 1];
		else
			table->philos[i].r_fork = &table->forks[i - 1];
		i++;
	}
}

static void	innit_forks(long philo_nbr, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < philo_nbr)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	innit_all(t_store *table, pthread_mutex_t *forks)
{
	innit_forks(table->philo_nbr, forks);
	innit_philos(table);
}
