/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacha <sacha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:20:26 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/06/11 17:38:00 by sacha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data data;
	
	if (error_handler(ac, av))
		return (1);
	if (!init_params(&data, ac, av))
		return (1);
	if (!init_forks(&data))
		return (1);
	if (!init_philos(&data))
		return (1);
	if (!launch_threads(&data))
		return (1);
	return (0);
}