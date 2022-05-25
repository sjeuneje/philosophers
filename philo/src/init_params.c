#include "philo.h"
#include "init_params.h"
#include "libft.h"

int	init_params(t_params *params, int ac, char **ar)
{
	params->n_philo = ft_atoi(ar[1]);
	params->t_die = ft_atoi(ar[2]);
	params->t_eat = ft_atoi(ar[3]);
	params->t_sleep = ft_atoi(ar[4]);
	if (ac == 6)
		params->nb_philo_must_eat = ft_atoi(ar[5]);
	return (0); 
}
