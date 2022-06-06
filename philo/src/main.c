#include "philo.h"
#include "errors_handler.h"
#include "init_params.h"
#include "threads_handler.h"

// 1. parsing
// 2. init philos structs
// 3. exec philo

t_philo	*init_philos(t_params *params)
{
    int     i;
	t_philo	*philos;

    i = 0;
    philos = malloc(params->n_philo * sizeof(t_philo));
    if (!philos)
        return (NULL);
    while (i < params->n_philo)
    {
        philos[i].num = i + 1;
        philos[i].params = params;
		i++;
    }
    return (philos);
}

int	main(int ac, char **av)
{
	t_params	params;
	t_philo		*philos;

	if (error_handler(ac, av))
		return (1);
	init_params(&params, ac, av);
	philos = init_philos(&params);
	if (!philos)
		return (2);
	if (!launch_threads(philos))
		return (3);
	printf("nphilos: %d, t_die: %d, t_eat: %d, t_sleep: %d\n", params.n_philo, params.t_die, params.t_eat, params.t_sleep);
	return (0);
}
