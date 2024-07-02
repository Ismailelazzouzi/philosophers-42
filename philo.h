#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_store
{
	long	philo_nbr;
	long	t_t_d;
	long	t_t_e;
	long	t_t_s;
	long	meals_limit;
	long	start;
	bool	end;
}	t_store;

void	parse(t_store *table, char **argv);
void	error(char *str);