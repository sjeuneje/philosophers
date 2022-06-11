/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:18:14 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/06/09 18:27:58 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_params(t_data *data, int ac, char **ar)
{
	data->forks = NULL;
	data->philos = NULL;
	data->nb_philo = ft_atoi(ar[1]);
	data->time_die = ft_atoi(ar[2]);
	data->time_eat = ft_atoi(ar[3]);
	data->time_sleep = ft_atoi(ar[4]);
	if (ac == 6)
		data->nb_philo_must_eat = ft_atoi(ar[5]);
	else
		data->nb_philo_must_eat = 0;
	if (pthread_mutex_init(&(data->talk), NULL))
		return (0);
	if (pthread_mutex_init(&(data->eat), NULL))
		return (0);
	return (1);
}

int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (0);
	while (++i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (0);
	}
	return (1);
	
}

int	init_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	data->philos = (t_philo *)malloc((sizeof(t_philo) * data->nb_philo));
	if (!data->philos)
		return (0);
	i = -1;
	philos = data->philos;
	while (++i < data->nb_philo)
	{
		philos[i].num = i + 1;
		philos[i].nb_eats = data->nb_philo_must_eat;
		philos[i].is_alive = 1;
		philos[i].last_eat = ft_get_time();
		philos[i].fork_r = &(data->forks[i]);
		if (i == 0)
			philos[i].fork_l = &(data->forks[data->nb_philo - 1]);
		else
			philos[i].fork_l = &(data->forks[i - 1]);
	}
	return (1);
}