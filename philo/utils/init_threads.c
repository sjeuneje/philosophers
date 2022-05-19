#include "threads_utils.h"
#include "routine_threads.h"

void	*init_threads(int nb_threads)
{
	int			i;
	pthread_t	*threads;

	i = 0;
	threads = malloc(sizeof(pthread_t) * (nb_threads + 1));
	if (!threads)
		return (NULL);
	while (i < nb_threads)
	{
		pthread_create(&threads[i], NULL, &routine, NULL);
		i++;
	}
	threads[i] = NULL;
	return (threads);
}

void	close_threads(pthread_t *threads)
{
	int	i;

	i = 0;
	while (threads[i])
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}