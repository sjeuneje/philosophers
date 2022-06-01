#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct	s_params
{
	int	n_philo;
	int	nb_philo_must_eat;
	int	t_die;
	int	t_eat;
	int	t_sleep;
}				t_params;

typedef struct	s_philo
{
	int			num;
	pthread_t	t;
	t_params	*params;
}				t_philo;

#endif 