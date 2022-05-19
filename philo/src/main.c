#include "philo.h"
#include "threads_utils.h"

int	main(int ac, char **av)
{
	pthread_t	*threads;

	threads = init_threads(2);
	if (!threads)
		return (1);
	close_threads(threads);
	return (0);
}