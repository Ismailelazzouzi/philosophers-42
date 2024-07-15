#include "philo.h"

static int	ft_isspace(char c)
{
	if (c >= 9 && c <= 13 || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static const char	*valid_nbr(const char *str)
{
	const char	*number;
	int			len;

	len = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("please only give positive numbers");
	number = str;
	while (ft_isdigit(*str++))
		len++;
	if (len > 10)
		error_exit("number too big");
	return (number);
}

static long	ft_atoi(const char *str)
{
	long	number;

	number = 0;
	str = valid_nbr(str);
	while (ft_isdigit(*str) == 1)
		number = (number * 10) + (*str++ - 48);
	if (number > INT_MAX)
		error_exit("number too big");
	return (number);
}

void	parse(t_store *table, char **argv)
{
	table->philo_nbr = ft_atoi(argv[1]);
	if (table->philo_nbr == 0 || table->philo_nbr > 200)
		error_exit("incorrect philo number");
	table->t_t_d = ft_atoi(argv[2]);
	table->t_t_e = ft_atoi(argv[3]);
	table->t_t_s = ft_atoi(argv[4]);
	if (table->t_t_d < 60 || table->t_t_e < 60 || table->t_t_s < 60)
		error_exit("timestamp less than 60ms");
	if (argv[5])
		table->meals_limit = ft_atoi(argv[5]);
	else
		table->meals_limit = -1;
	table->died = 0;
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->eat_lock, NULL);
}
