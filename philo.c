#include "philo.h"

int main(int argc, char **argv)
{
	t_store	table;
	if (argc == 5 || argc == 6)
	{
		parse(&table, argv);
		printf("%lu\n%lu\n%lu\n%lu\n%lu\n", table.philo_nbr, 
		table.t_t_d, table.t_t_e, table.t_t_s, table.meals_limit);
	}
	else
		printf("invalid input\n");
	return (0);
}