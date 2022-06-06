#include "philo.h"
#include "threads_handler.h"
#include "mutex_handler.h"

int	is_eating(int ms)
{
	cur_time = ft_get_time();
	while ()
	usleep(ms * 1000);
	return (0);
}

void    *routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(philo->fork_l); // pas oublier de protéger
		printf("%d %d has taken a fork", philo->params->t_eat, philo->params->n_philo); // transformer t eat avec gettimeofday ...
		pthread_mutex_lock(philo->fork_r);
		printf("%d %d has taken a fork", philo->params->t_eat, philo->params->n_philo); // transformer t eat avec gettimeofday ...
		while (is_eating(philo->params->t_sleep))
		{
			printf("")
		}
	}
    return (NULL);
}

int	launch_threads(t_philo *philos)
{
	int	i;

	i = 0;
	if (!init_mutex(philos))
		return (0);
	while (i < philos->params->n_philo)
	{
		if (pthread_create(&philos[i].t, NULL, &routine, (void *)&philos[i]) != 0)
			return (0);
		i++;
	}
	// destroy mutex
	i = 0;
	while (i < philos->params->n_philo)
	{
		if (pthread_join(philos[i].t, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}