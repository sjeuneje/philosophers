#ifndef THREADS_UTILS_H
# define THREADS_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

void	*init_threads(int nb_threads);
void	close_threads(pthread_t *threads);

#endif