#include "philo.h"
#include "threads_handler.h"

void    *routine()
{
    printf("ok\n");
    return (NULL);
}

void    *init_philos(t_params *params)
{
    int     i;
    t_philo *philos;

    i = 0;
    philos = malloc(params->n_philo * sizeof(t_philo));
    if (!philos)
        return (NULL);
    while (i < params->n_philo)
    {
        philos[i].num = i + 1;
        philos[i].params = params;
        if (!pthread_create(&philos[i].t, NULL, &routine, NULL))
            return (NULL);
        if (!pthread_join(philos[i].t, NULL))
            return (NULL);
    }
    return (philos);
}