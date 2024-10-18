/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <isel-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:18:25 by isel-azz          #+#    #+#             */
/*   Updated: 2024/10/18 07:18:55 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>

typedef struct s_philo
{
	struct s_store	*table;
	unsigned int	philo_id;
	unsigned int	meals_eaten;
	long			last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_t		philo;
}	t_philo;

typedef struct s_store
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	print_lock;
	long			philo_nbr;
	long			t_t_d;
	long			t_t_e;
	long			t_t_s;
	long			meals_limit;
	long			dinner_start;
	int				died;
}	t_store;

void	check_args(char **args);
void	parse(t_store *table, char **argv);
size_t	get_current_time(void);
void	ft_usleep(size_t milliseconds);
void	error_exit(char *str);
void	destroy_all(char *str, t_store *table);
void	innit_all(t_store *table, pthread_mutex_t *forks);
int		create_threads(t_store *table);
int		dead_loop(t_philo *philo);
void	*monitoring(void *pointer);
void	print_message(char *str, t_philo *philo, unsigned int id);
void	think(t_philo *philo);
void	dream(t_philo *philo);
void	eat(t_philo *philo);