#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_params
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_philo_must_eat;
}				t_params;

typedef struct	s_philo
{
	// numero de philo
	t_params	*params;
}				t_philo;

#endif 