#include "philo.h"
#include "errors_handler.h"
#include "init_params.h"
#include "threads_handler.h"

// 1. parsing
// 2. init philos structs
// 3. exec philo

int	main(int ac, char **av)
{
	t_params	params;
	t_philo		*philos;

	if (error_handler(ac, av))
		return (1);
	init_params(&params, ac, av);
	philos = init_philos(&params);
	if (!philos)
		return (1);
	printf("nphilos: %d, t_die: %d, t_eat: %d, t_sleep: %d\n", params.n_philo, params.t_die, params.t_eat, params.t_sleep);
	return (0);
}
