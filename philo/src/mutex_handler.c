#include "mutex_handler.h"
#include "philo.h"

static void	*allocate_mutex(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->params->n_philo)
	{
		philos->fork_l = malloc((sizeof(pthread_mutex_t)));
		if (!philos->fork_l)
			return (NULL);
		philos->fork_r = malloc((sizeof(pthread_mutex_t)));
		if (!philos->fork_r)
			return (NULL);
		i++;
	}
	return ("ok");
}

int	init_mutex(t_philo *philos)
{
	int	i;

	i = 1;
	if (!allocate_mutex(philos))
		return (0);
	if (pthread_mutex_init(philos[0].fork_l, NULL) != 0)
			return (0);
	if (pthread_mutex_init(philos[0].fork_r, NULL) != 0)
		return (0);
	while (i < philos->params->n_philo)
	{
		philos[i].fork_l = philos[i - 1].fork_l;
		if (pthread_mutex_init(philos[0].fork_r, NULL) != 0)
			return (0);	
		i++;
	}
	return (1);
}

int	close_mutex(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->params->n_philo)
	{
		if (pthread_mutex_destroy(philos[i].fork_r) != 0)
			return (0);
		if (pthread_mutex_destroy(philos[i].fork_l) != 0)
			return (0);
		i++;
	}
	return (1);
}