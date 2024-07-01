#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_store	t_store;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals;
	bool		full;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_store		*table;
}	t_philo;

typedef struct s_store
{
	long	philo_nbr;
	long	t_t_d;
	long	t_t_e;
	long	t_t_s;
	long	meals_limit;
	long	start;
	bool	end;
	t_fork	*forks;
	t_philo	*philos;
}	t_store;

void	parse(t_store *table, char **argv);
void	error(char *str);