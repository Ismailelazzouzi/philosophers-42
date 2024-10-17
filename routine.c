#include "philo.h"

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->philo_id);
}

void	dream(t_philo *philo)
{
	print_message("is sleeping", philo, philo->philo_id);
	ft_usleep(philo->table->t_t_s);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message("has taken a fork", philo, philo->philo_id);
	if (philo->table->philo_nbr == 1)
	{
		ft_usleep(philo->table->t_t_d);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo, philo->philo_id);
	print_message("is eating", philo, philo->philo_id);
	pthread_mutex_lock(&philo->table->eat_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->eat_lock);
	ft_usleep(philo->table->t_t_e);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}