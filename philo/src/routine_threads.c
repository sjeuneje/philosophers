#include "philo.h"
#include "routine_threads.h"

void	*routine()
{
	printf("Threads...\n");
	sleep(3);
	printf("Ending threads.\n");
	return (NULL);
}