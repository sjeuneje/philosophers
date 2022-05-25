#include "philo.h"
#include "errors_handler.h"
#include "init_params.h"

// 1. parsing
// 2. init philos structs
// 3. exec philo

int	main(int ac, char **av)
{
	t_params	params;

	if (error_handler(ac, av))
		return (1);
	if (init_params(&params, ac, av))
		return (1);
	printf("ok\n");
	return (0);
}
