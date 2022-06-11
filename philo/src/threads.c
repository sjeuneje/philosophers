/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacha <sacha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:54:59 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/06/11 17:43:49 by sacha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	if (philo->data->nb_philo == 1)
	{
		print_message(philo, "has taken a fork");
		ft_wait_philo(philo->data->time_die);
		return (NULL);
	}
	if (philo->num % 2 != 0)
		ft_wait_philo(2);
	while (!philo->data->stop && !philo->data->full)
	{
		is_eating(philo);
		print_message(philo, "is sleeping");
		ft_wait_philo(philo->data->time_sleep);
		print_message(philo, "is thinking");
	}
	return (NULL);
}

void	threads_monitoring(t_data *data)
{
	int	i;

	while (!data->full)
	{
		i = -1;
		while (++i < data->nb_philo && !data->stop)
		{
			pthread_mutex_lock(&(data->eat));
			if ((int)(ft_get_time() - data->philos[i].last_eat) > data->time_die)
			{
				print_message(&(data->philos[i]), "died");
				pthread_mutex_lock(&(data->talk));
				data->stop = 1;
			}
			pthread_mutex_unlock(&(data->eat));
		}
		if (data->stop)
			break ;
		i = 0;
		while (data->nb_philo_must_eat && i < data->nb_philo && data->philos[i].nb_eats >= data->nb_philo_must_eat)
			i++;
		data->full = (i == data->nb_philo);
	}
}

int	launch_threads(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = ft_get_time();
	data->stop = 0;
	data->full = 0;
	while (++i < data->nb_philo)
		if (pthread_create(&data->philos[i].t, NULL, routine_philo, &(data->philos[i]))) return (0);
	threads_monitoring(data);
	pthread_mutex_unlock(&(data->talk));
	i = -1;
	while (++i < data->nb_philo)
		if (pthread_join(data->philos[i].t, NULL)) return (1);
	return (1);
}