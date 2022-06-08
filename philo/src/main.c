#include "philo.h"
#include "errors_handler.h"
#include "init_params.h"

int	main(int ac, char **av)
{
	t_params	params;

	if (error_handler(ac, av))
		return (1);
	init_params(&params, ac, av);
	
	printf("nphilos: %d, t_die: %d, t_eat: %d, t_sleep: %d\n", params.n_philo, params.t_die, params.t_eat, params.t_sleep);
	return (0);
}
