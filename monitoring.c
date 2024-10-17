#include "philo.h"

void	print_message(char *str, t_philo *philo, unsigned int id)
{
	long	time;

	pthread_mutex_lock(&philo->table->print_lock);
	time = get_current_time() - philo->table->dinner_start;
	if (!dead_loop(philo))
		printf("%lu %d %s\n", time, id, str);
	pthread_mutex_unlock(&philo->table->print_lock);
}

int	philosopher_dead(t_philo *philo, long time_to_die)
{
	pthread_mutex_lock(&philo->table->eat_lock);
	if (get_current_time() - philo->last_meal >= time_to_die)
		return (pthread_mutex_unlock(&philo->table->eat_lock), 1);
	pthread_mutex_unlock(&philo->table->eat_lock);
	return (0);
}

static int	check_if_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].table->philo_nbr)
	{
		if (philosopher_dead(&philos[i], philos[i].table->t_t_d))
		{
			print_message("died", &philos[i], philos[i].philo_id);
			pthread_mutex_lock(&philos[0].table->dead_lock);
			philos->table->died = 1;
			pthread_mutex_unlock(&philos[0].table->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_if_all_ate(t_philo *philos)
{
	int	i;
	int	done_eating;

	i = 0;
	done_eating = 0;
	if (philos[0].table->meals_limit == -1)
		return (0);
	while (i < philos[0].table->philo_nbr)
	{
		pthread_mutex_lock(&philos[i].table->eat_lock);
		if (philos[i].meals_eaten >= philos[i].table->meals_limit)
			done_eating++;
		pthread_mutex_unlock(&philos[i].table->eat_lock);
		i++;
	}
	if (done_eating == philos[0].table->philo_nbr)
	{
		pthread_mutex_lock(&philos[0].table->dead_lock);
		philos->table->died = 1;
		pthread_mutex_unlock(&philos[0].table->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitoring(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	while (1)
		if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	return (pointer);
}