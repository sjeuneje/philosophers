/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacha <sacha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:16:02 by sacha             #+#    #+#             */
/*   Updated: 2022/06/11 17:25:57 by sacha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *message)
{
	unsigned long	time;

	pthread_mutex_lock(&(philo->data->talk));
	time = ft_get_time() - philo->data->start_time;
	if (!philo->data->stop && !philo->data->full)
		printf("%lu %d %s\n", time, philo->num, message);
	pthread_mutex_unlock(&(philo->data->talk));
}

void	ft_wait_philo(int ms)
{
	unsigned long	time;

	time = ft_get_time();
	while (ft_get_time() < time + ms)
		usleep(10);
}

void	is_eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(philo->fork_r);
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_l);
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(&(data->eat));
	print_message(philo, "is eating");
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&(data->eat));
	ft_wait_philo(data->time_eat);
	philo->nb_eats++;
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}