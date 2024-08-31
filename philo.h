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
	unsigned int	eat_flag;
	int				died;
}	t_store;

// parse.c
void	parse(t_store *table, char **argv);
// utils.c
size_t	get_current_time(void);
void		ft_usleep(size_t milliseconds);
void	error_exit(char *str);
void	destroy_all(char *str, t_store *table);
// innit.c
void	innit_all(t_store *table, pthread_mutex_t *forks);
// threads.c
int	create_threads(t_store *table);
int	dead_loop(t_philo *philo);
// monitor.c
void	*monitoring(void *pointer);
void	print_message(char *str, t_philo *philo, unsigned int id);
// routine.c
void	think(t_philo *philo);
void	dream(t_philo *philo);
void	eat(t_philo *philo);