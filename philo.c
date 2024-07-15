#include "philo.h"

void	leakcheck(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	atexit(leakcheck);
	t_store			table;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	table.philos = philos;
	table.forks = forks;
	if (argc == 5 || argc == 6)
	{
		parse(&table, argv);
		innit_all(&table, forks);
		create_threads(&table);
		destroy_all(NULL, &table);
	}
	else
		return (write(2, "Wrong argument count\n", 22), 1);
	return (0);
}
