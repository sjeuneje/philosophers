/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:39:30 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/06/09 13:55:08 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_get_time()
{
	struct timeval	time;
	unsigned long	curr_time;
	
	gettimeofday(&time, NULL);
	curr_time = 1000 * time.tv_sec + time.tv_usec / 1000;
	return (curr_time);
}

int	ft_atoi(char *s)
{
	int	n;
	int	i;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
		return (0);
	n = 0;
	while (s[i])
	{
		if (s[i] > 57 || s[i] < 48)
			return (0);
		n = (n * 10) + (s[i++] - 48);
		if (n > 2147483647)
			return (0);
	}
	if (!n)
		return (0);
	return (n);
}