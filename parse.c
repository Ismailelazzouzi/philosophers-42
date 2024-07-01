#include "philo.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if (c >= 9 && c <= 13 || c == 32)
		return (1);
	return (0);
}

static const char	*skip(const char *str)
{
	const char	*ret;
	int		len;

	len = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error("No negative values!");
	if (!ft_isdigit(*str))
		error("Give me correct digits you stupid!");
	ret = str;
	while (ft_isdigit(*str++))
		len++;
	if (len > 10)
		error("no value should be more than INT_MAX !");
	return (ret);
}

static long	ft_atol(const char *str)
{
	long	number;

	number = 0;
	str = skip(str);
	while (ft_isdigit(*str))
		number = (number * 10) + (*str++ - 48);
	if (number > INT_MAX)
		error("no value should be more than INT_MAX !");
	return (number);
}

void	parse(t_store *table, char **argv)
{
	table->philo_nbr = ft_atol(argv[1]);
	table->t_t_d = ft_atol(argv[2]) * 1000;
	table->t_t_e = ft_atol(argv[3]) * 1000;
	table->t_t_s = ft_atol(argv[4]) * 1000;
	if (table->t_t_d < 60000 || table->t_t_e < 60000 || table->t_t_s < 60000)
		error("Minimum timestamp is 60ms");
	if (argv[5])
		table->meals_limit = ft_atol(argv[5]);
	else
		table->meals_limit = -1;
}
