#include "philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead_lock);
	if (philo->table->died == 1)
		return (pthread_mutex_unlock(&philo->table->dead_lock), 1);
	pthread_mutex_unlock(&philo->table->dead_lock);
	return (0);
}

static void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->philo_id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}

int	create_threads(t_store *table)
{
	pthread_t	monitor;
	int			i;

	if (pthread_create(&monitor, NULL, &monitoring, table->philos) != 0)
		destroy_all("error creating threads", table);
	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_create(&table->philos[i].philo, NULL,
				&routine, &table->philos[i]) != 0)
			destroy_all("error creating threads", table);
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
		destroy_all("Thread join error", table);
	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_join(table->philos[i].philo, NULL) != 0)
			destroy_all("Thread join error", table);
		i++;
	}
	return (0);
}