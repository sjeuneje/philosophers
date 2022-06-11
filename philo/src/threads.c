/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:54:59 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/06/09 18:45:12 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *philo)
{
	(void)philo;
	return (NULL);
}

void	threads_monitoring(t_data *data)
{
	(void)data;
	return ;
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